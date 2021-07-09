#ifndef PRACTICE_FUNCTIONSFORPRACTICE_H
#define PRACTICE_FUNCTIONSFORPRACTICE_H
#pragma once

#include "iostream"
#include "string"
#include "fstream"


int** matrix_input(int rang){
    int** matrix;
    int method;
    cout << "Choose how you want to enter the matrix\n1.Keyboard input\2Input from file" << endl;
    cin >> method;
    cout << "Enter the matrix";
    switch (method) {
        case 1:{
            matrix = new int* [rang];
            for (int i = 0; i < rang; i++){
                matrix [i] = new int [rang];
                for (int j = 0; j < 0; j++){
                    cin >> matrix[i][j];
                }
            }
            return matrix;
        }
        case 2:{
            string path;
            ifstream fin;
            cout << "Please enter the path" << endl;
            cin >> path;
            fin.open(path);
            if (!fin.is_open()){
                cout << "File open error!";
            }
            else{

            }
        }
    }
}

#endif //PRACTICE_FUNCTIONSFORPRACTICE_H
