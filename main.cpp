#include <iostream>
#include <stdio.h>
#include "FunctionsForPractice.h"
#include "CRS.h"

using namespace std;

int main() {
    int number;
    cout <<"Please choose number of task" << endl;
    cin >> number;
    switch (number) {
        case 1:{
            int** digraph;
            int edges, jj;
            jj = 2;
            cout << "Enter the number of edges" <<endl;
            cin >> edges;
            digraph = digraph_input(edges);
            print_arr(digraph, edges, jj);
            break;
        }
        case 2:{
            int** digraph;
            int** matrix;
            int edges, vertices;
            cout << "Enter the number of edges and vertices" <<endl;
            cin >> edges >> vertices;
            digraph = digraph_input(edges);
            matrix = adjacency_matrix(digraph, edges, vertices);
            print_arr(matrix, vertices,vertices);
            CRS test (matrix, vertices);
            test.print_CRS();
            break;
        }
    }
    return 0;
}
