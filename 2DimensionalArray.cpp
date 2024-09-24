#include <iostream>
using namespace std;
int main() {
	int array1[2][3];
	int array2[2][3];
	int row,column,x,y;
	cout << "Enter rows  and columns of matrix: ";
	cin >> row >> column;
	cout << "Enter elements of matrix: " << endl;
	for (x = 0; x < row; ++x) 
		for (y = 0; y < column; ++y) {
			cout << "Enter elements a" << x + 1 << y + 1 << ":";
			cin >> array1[x][y]; 
		}
		for(x = 0; x < row; ++x) {
			for(y = 0; y < column; ++y) {
           		array2[y][x]=array1[x][y];
       		}
		}
		cout << "Entered matrix: " << endl;
		for (x = 0; x < row; ++x) {
			for (y = 0; y < column; ++y) {
				cout << " " << array1[x][y];
				if (y == column - 1) {
					cout << endl << endl;
				}
			}
		}
		cout << endl << "Transpose of matrix: " << endl;
		for (x = 0; x < column; ++x) {
			for (y = 0; y < row; ++y) {
				cout << " " << array2[x][y];
				if(y == row-1) {
					cout << endl << endl;
				}
			}
		}
}
