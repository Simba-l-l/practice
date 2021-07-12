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

void resize_helper (int** &arr, int &size, int &resize){
    int** helper = new int* [2];
    for (int i = 0; i < 2; i++){
        helper[i] = new int[size + resize];
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < size; j++){
            helper[i][j] = arr [i][j];
        }
    }
    //delete[] arr;
    size = size + resize;
    arr = helper;
}
int comp1 (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int* glue_arr(int* &arr1, int* &arr2, int &len1, int &len2, int &len_rez){
    int* data = new int [len1 + len2];
    int*rez = new int [len_rez];
    for (int i = 0; i < len1; i++){
        data[i] = arr1[i];
    }
    for (int i = 0; i < len2; i++){
        data[i+len1] = arr2[i];
    }
    qsort(data, len1+len2, sizeof (int), comp1);
    for (int i = 1; i < len1+len2; i++){
        if (data[i] == data[i-1]){
            for (int j = i; j < len1 + len2 - 1; j++){
                data[j] = data[j+1];
            }
        }
    }
    for (int i = 0; i < len_rez; i++){
        rez[i] = data[i];
    }
    delete[] data;
    return rez;
}


int** addition_helper(int** &arr1, int** &arr2, int &size1, int &size2){
    int** temp = new int*[2];
    temp [0] = new int[size1 + size2];
    temp [1] = new int[size1 + size2];
    for(int i = 0; i < size1; i ++){
        temp[0][i] = arr1[0][i];
        temp[1][i] = arr1[1][i];
    }
    for(int i = 0; i < size2; i ++){
        temp[0][i + size1] = arr2[0][i];
        temp[1][i + size1] = arr2[1][i];
    }
    size1 = size1 + size2;
//    for (int i = 0; i < 2; i ++){
//        delete [] arr1[i];
//        delete [] arr2[i];
//    }
//    delete[] arr1;
//    delete[] arr2;
    //11
    return temp;
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
