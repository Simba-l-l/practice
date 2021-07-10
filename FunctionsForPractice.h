//
// Created by mikhail on 09.07.2021.
//

#ifndef PR1_FUNCTIONSFORPRACTICE_H
#define PR1_FUNCTIONSFORPRACTICE_H
#pragma once

//#include "iostream"
#include "string"
#include "fstream"

using namespace std;

int** digraph_input(int &edges) {
    int **digraph = nullptr;
    int method;
    cout << "Choose how you want to enter the digraph"<< endl;
    cout << "1.Keyboard input\n2.Input from file" <<endl;
    cin >> method;
    switch (method) {
        case 1: {
            cout << "Enter the digraph" << endl;
            digraph = new int *[edges];
            for (int i = 0; i < edges; i++) {
                digraph[i] = new int[2];
                for (int j = 0; j < 2; j++) {
                    cin >> digraph[i][j];
                }
            }
            break;
        }
        case 2: {
            string path;
            ifstream fin;
            //cout << "Please enter the path" << endl;
            //cin >> path;
            path = "/home/mikhail/Рабочий стол/pr1/input.txt";
            fin.open(path);
            if (!fin.is_open()) {
                cout << "File open error!";
            }
            else {
                char ch;
                int k = 0;
                int ii;
                digraph = new int* [edges];
                for (int i = 0; i < edges; i++){
                    digraph[i] = new int [2];
                }
                while (!fin.eof() && k < edges * 2){
                    fin >> ii;
                    digraph[k / 2][k % 2] = ii;
                    k++;
                }
            }
            fin.close();
            break;
        }
    }
    return digraph;
}


int** adjacency_matrix(int** &digraph, int &edges, int &vertices){
    int** matrix = new int*[vertices];
    for (int i = 0; i < vertices; i++ ){
        matrix[i] = new int [vertices];
        for (int j = 0; j < vertices; j++){
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < edges; i++){
        matrix[digraph[i][0] -1 ][digraph[i][1] - 1] = 1;
    }
    return matrix;
}



void print_arr(int** &arr, int &ii, int &jj){
    for(int i = 0; i < ii; i++){
        for (int j = 0; j < jj; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

#endif //PR1_FUNCTIONSFORPRACTICE_H
