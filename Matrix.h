#ifndef PRACTICE_MATRIX_H
#define PRACTICE_MATRIX_H
#pragma once

using namespace std;

class Matrix{
private:
    int n ;
    double** data;
public:
    Matrix(int count, int X){
        n = count;
        data = new double* [n];
        for (int i = 0; i < n; i++){
            data[i] = new double [n];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("a[%d][%d] =", i, j);
                cin >>data[i][j];
            }
        }
    }

    Matrix(int count){
        n = count;
        data = new double*[n];
        for (int i = 0; i < n; i++){
            data[i] = new double [n];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                data[i][j] = 1./double (i + j + 1);
            }
        }
    }

    Matrix(){
        n = 2;
        data = new double*[n];
        for (int i = 0; i < n; i++){
            data[i] = new double [n];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                data[i][j] = 1;
            }
        }
    }

    ~Matrix(){
        printf("The destructor was called\n");
        for(int i = 0; i < n; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void Print(){
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << data[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

#endif //PRACTICE_MATRIX_H
