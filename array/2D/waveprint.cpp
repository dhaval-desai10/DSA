#include<iostream>
#include<vector>
using namespace std;

void printlikewave(vector<vector<int>>arr, int nrow, int ncol) {
    for(int col = 0; col < ncol; col++) {
        if(col % 2 == 0) {
            for(int row = 0; row < nrow; row++) {
                cout << arr[row][col] << " ";
            }
            cout<<endl;
        } else {
            for(int row = nrow - 1; row >= 0; row--) {
                cout << arr[row][col] << " ";
            }
            cout<<endl;
        }
    }
}

int main() {
    int nrow, ncol;
    cout << "Enter the number of rows: ";
    cin >> nrow;
    cout << "Enter the number of columns: ";
    cin >> ncol;

    vector<vector<int>> arr(nrow, vector<int>(ncol));

    cout << "Enter the elements of the 2D array: " << endl;
    for(int i = 0; i < nrow; i++) {
        for(int j = 0; j < ncol; j++) {
            cin >> arr[i][j];
        }
    }

    
    cout << "Printing the 2D array in wave pattern: " << endl;
    printlikewave(arr, nrow, ncol);

    return 0;
}