#include<iostream>
using namespace std;

int main()
{
    int rows, col;
    cout << "Enter number of rows: " << endl;
    cin >> row;

    cout << "Enter number of coloumns: " << endl;
    cin >> col;

    cout << "Enter size of each coloumn: " << endl;
    int** ptr = new int* [row];

    for (int i = 0; i < rows; i++) {
        ptr[i] = new int[cols[i]];
    }


    return 0;
}