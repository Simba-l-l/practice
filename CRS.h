//
// Created by mikhail on 10.07.2021.
//

#ifndef PR1_CRS_H
#define PR1_CRS_H
#pragma once
#include "fstream"
#include "string"
#include "FunctionsForPractice.h"

struct CRS {
public:
    int* values;
    int* columns;
    int* rowindex;
    int length, rang;
    CRS(){
        rang = 0;
        length = 0;
    }
    CRS(int* v, int* c, int* r, int l, int ra ){
        values = v;
        columns = c;
        rowindex = r;
        length = l;
        rang = ra;
    }

    CRS(int** &matrix, int rang_m) {
        rang = rang_m;
        length = 0;
        for (int i = 0; i < rang; i++) {
            for (int j = 0; j < rang; j++) {
                if (matrix[i][j] != 0) {
                    length++;
                }
            }
        }
        values = new int[length];
        columns = new int[length];
        rowindex = new int[rang+ 1];
        rowindex[0] = 0;
        int count = 0;
        for (int i = 0; i < rang; i++) {
            for (int j = 0; j < rang; j++) {
                if (matrix[i][j] != 0) {
                    values[count] = matrix[i][j];
                    columns[count] = j;
                    count++;
                }
                rowindex[i + 1] = count;
            }
        }
    }

    int** get_matrix() const{
        int** result = new int*[rang];
        int count = 0;
        for (int i = 0; i < rang; i ++){
            result[i] = new int[rang];
        }
        for (int i = 0; i < rang; i++){
            for (int j = 0; j < rang; j++){
                result [i][j] = 0;
            }
        }
        for (int i = 0 ; i < rang + 1; i++){
            for (int j = count; j < rowindex[i]; j++){
                result[i - 1][columns[j]] = values[j];
                count++;
            }
        }
        return result;
    }


    void print_CRS() const{
      int method;
      cout << "Chouse the output method \n1.Console output \n2.File output"<< endl;
      cin >> method;
        switch (method) {
            case 1:{
                cout << "values:" << endl;
                for(int i = 0; i < length; i++){
                    cout << values[i] << " ";
                }
                cout << "\ncolumns:" << endl;
                for(int i = 0; i < length; i++){
                    cout << columns[i] << " ";
                }
                cout << "\nrow index:" << endl;
                for(int i = 0; i < rang + 1; i++){
                    cout << rowindex[i] << " ";
                }
                cout << endl;
                break;
                default:{
                    cout << "Method selection error" << endl;
                }
            }
            case 2:{
                ofstream fout;
                fout.open("/home/mikhail/Рабочий стол/pr1/output.txt");
                if (!fout.is_open()){
                    cout <<"File output error!" << endl;
                }
                else{
                    for(int i = 0; i < length; i++){
                        fout << values[i] << " ";
                    }
                    fout << endl;
                    for(int i = 0; i < length; i++){
                        fout << columns[i] << " ";
                    }
                    fout << endl;
                    for(int i = 0; i < rang + 1; i++){
                        fout << rowindex[i] << " ";
                    }
                    fout.close();
                    cout << "Check file output.txt" <<endl;
                }
                break;
            }
        }
    }



    CRS operator + (const CRS & other) {
        CRS temp;
        if (this->rang != other.rang){
            cout << "Аddition error!\n" <<"the ranks of the matrices are different" << endl;
            return temp;
        }
        temp.rang = this->rang;
        temp.rowindex = new int[temp.rang + 1];
        temp.rowindex[0] = 0;
        int** helper_1 = new int*[2];
        int** helper_2 = new int*[2];
        int** helper_result = new int*[2];
        int** final_helper_result = new int*[2];
        int num_in_line_1, num_in_line_2, count_1, count_2, result_resize , counter, result_size, temp1, temp2, size_fhr;
        size_fhr = 0;
        count_1 = 0;
        count_2 = 0;
        for (int i = 1; i < rang + 1 ; i++){
            temp.rowindex[i] = temp.rowindex[i-1];
            result_size = 0;
            result_resize = 0;
            counter = 0;
            num_in_line_1 = this->rowindex[i] - this->rowindex[i-1];
            num_in_line_2 = other.rowindex[i] - other.rowindex[i-1];
            for (int j = 0; j < 2; j++){
                helper_1[j] = new int [num_in_line_1];
                helper_2[j] = new int [num_in_line_2];
            }
            for (int j = 0; j < num_in_line_1; j++){
                helper_1[0][j] = this->values[count_1 + j];
                helper_1[1][j] = this->columns[count_1 + j];
            }
            count_1 += num_in_line_1;
            for (int j = 0; j < num_in_line_2; j++){
                helper_2[0][j] = other.values[count_2 + j ];
                helper_2[1][j] = other.columns[count_2 + j];

            }
            count_2 += num_in_line_2;
            for (int j = 0; j < num_in_line_1; j++){
                for (int k = 0; k < num_in_line_2; k++){
                    if (helper_1[1][j] == helper_2[1][k] ){
                        counter++;
                    }
                }
            }
            result_resize = num_in_line_1 + num_in_line_2 - counter;
            resize_helper(helper_result, result_size, result_resize);
            helper_result[1] = glue_arr(helper_1[1], helper_2[1], num_in_line_1, num_in_line_2, result_size);
            for (int j = 0; j < result_size; j++){
                temp1 = 0;
                temp2 = 0;
                for(int k = 0; k < num_in_line_1; k++) {
                    if (helper_1[1][k] == helper_result[1][j]) {
                        temp1 = helper_1[0][k];
                        break;
                    }
                }
                for(int k = 0; k < num_in_line_2; k++){
                    if (helper_2[1][k] == helper_result[1][j]){
                        temp2 = helper_2[0][k];
                        break;
                        }
                }
                if (temp1 != 0 || temp2 != 0){
                    temp.rowindex[i] += 1;
                }
                helper_result[0][j] = temp1 + temp2;
            }
            final_helper_result = addition_helper(final_helper_result, helper_result, size_fhr, result_size);
            for (int j = 0; j < 2; j++){
                delete[] helper_2[j] ;
                delete[] helper_1[j];
            }

        }
        temp.length = size_fhr;
        temp.values = final_helper_result[0];
        temp.columns = final_helper_result[1];
        delete []final_helper_result;
        return temp;
    }


    CRS operator * (const CRS & other)  {
        if (this->rang != other.rang){
            cout << "Multiplication error!\n" <<"the ranks of the matrices are different";
            CRS temp;
            return temp;
        }
        int** m1 = this->get_matrix();
        int** m2 = other.get_matrix();
        int** res = new int*[this->rang];
        for (int i = 0; i < this->rang; i++)
        {
            res[i] = new int[this->rang];
            for (int j = 0; j < this->rang; j++)
            {
                res[i][j] = 0;
                for (int k = 0; k < this->rang; k++)
                    res[i][j] += m1[i][k] * m2[k][j];
            }
        }
        CRS temp(res, this->rang);
        for (int i = 0; i < this->rang; i++){
            delete[] m1[i];
            delete[] m2[i];
            delete[] res[i];
        }
        delete[] m1;
        delete[] m2;
        delete[] res;
        return temp;
    }




    ~CRS(){
//        delete[] values;
//        delete[] columns;
//        delete[] rowindex;
    }
};


#endif //PR1_CRS_H
