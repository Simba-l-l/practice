//
// Created by mikhail on 10.07.2021.
//

#ifndef PR1_CRS_H
#define PR1_CRS_H
#pragma once
#include "fstream"

struct CRS {
public:
    int* values;
    int* columns;
    int* rowindex;
    int length = 0;
    int  rang = 0;
    CRS(int** &matrix, int &rang_m) {
        rang = rang_m;
        for (int i = 0; i < rang; i++) {
            for (int j = 0; j < rang; j++) {
                if (matrix[i][j] != 0) {
                    length++;
                }
            }
        }
        values = new int[length];
        columns = new int[length];
        rowindex = new int[length + 1];
        rowindex[0] = 0;
        int count = 0;
        int count_lines = 0;
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
    void print_CRS(){
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
};


#endif //PR1_CRS_H
