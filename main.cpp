#include <iostream>
#include "FunctionsForPractice.h"
#include "CRS.h"

using namespace std;

int main() {
    int number;
    while (true) {
        system("clear");
        cout << "Please choose number of task"
                "\n 1.Digraph input"
                "\n 2.Output of adjacency matrix in CRS format"
                "\n 3.Matrix addition and multiplication in CRS format"
                "\n ~.or any other character to exit" << endl;
        cin >> number;
        switch (number) {
            case 1: {
                int **digraph;
                int edges, jj;
                jj = 2;
                cout << "Enter the number of edges" << endl;
                 cin >> edges;
                digraph = digraph_input(edges);
                print_arr(digraph, edges, jj);
                //удаление мусора---------------------------------------------------
                for (int i = 0; i < edges; i++){
                    delete[] digraph[i];
                }
                delete[] digraph;
                //------------------------------------------------------------------
                break;
            }
            case 2: {
                int **digraph;
                int **matrix;
                int edges, vertices;
                cout << "Enter the number of edges and vertices" << endl;
                cin >> edges >> vertices;
                digraph = digraph_input(edges);
                matrix = adjacency_matrix(digraph, edges, vertices);
                print_arr(matrix, vertices, vertices);
                CRS test(matrix, vertices);
                test.print_CRS();
                //удаление мусора---------------------------------------------------
                for (int i = 0; i < edges; i++){
                    delete[] digraph[i];
                }
                delete[] digraph;
                for (int i = 0; i < vertices; i++){
                    delete[] matrix[i];
                }
                delete[] matrix;
                //------------------------------------------------------------------
                break;
            }
            case 3:{
                bool flag = true;
                int len1, len2, rang1, rang2, act;
                cout << "Enter length of first CRS matrix " << endl;
                cin >> len1;
                cout << "Enter rang of first CRS matrix " << endl;
                cin >> rang1;
                int* a1 = new int [len1];
                int* a2 = new int [len1];
                int* a3 = new int [rang1+1];
                cout << "Enter  values array " << endl;
                for (int i = 0; i < len1; i ++){
                    cin >> a1[i];
                }
                cout << "Enter  columns array " << endl;
                for (int i = 0; i < len1; i ++){
                    cin >> a2[i];
                }
                cout << "Enter  index row array " << endl;
                for (int i = 0; i < rang1+1; i ++){
                    cin >> a3[i];
                }
                cout << "Enter length of second CRS matrix " << endl;
                cin >> len2;
                cout << "Enter rang of second CRS matrix " << endl;
                cin >> rang2;
                int* b1 = new int [len2];
                int* b2 = new int [len2];
                int* b3 = new int [rang2+1];
                cout << "Enter  values array " << endl;
                for (int i = 0; i < len2; i ++){
                    cin >> b1[i];
                }
                cout << "Enter  columns array " << endl;
                for (int i = 0; i < len2; i ++){
                    cin >> b2[i];
                }
                cout << "Enter  index row array " << endl;
                for (int i = 0; i < rang1+1; i ++){
                    cin >> b3[i];
                }
                CRS a (a1, a2, a3, len1, rang1);
                CRS b (b1, b2, b3, len2, rang2);
                static CRS c;
                while (flag) {
                    cout << "Select an action\n"
                            " 1.Addition CRS\n"
                            " 2.Multiplication\n"
                            " ~.or any other character to exit" << endl;
                    cin >> act;
                    switch (act) {
                        case 1: {
                            c = a + b;
                            c.print_CRS();
                            break;
                        }
                        case 2: {
                            c = a * b;
                            c.print_CRS();
                            break;
                        }
                        default:
                            flag = false;
                            break;
                    }
                }
                break;
            }
            default:
                return 0;
        }
    }
}
