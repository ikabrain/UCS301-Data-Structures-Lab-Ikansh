// For a user-input square matrix, find out the LARGEST number in each row & column!

#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cout << "Enter size of square matrix: ";
	cin >> n;
	int mtrx[n][n];
	
	for (int i = 0; i < n; i++) {
		cout << "Enter row " << i+1 << ": ";
		for (int j = 0; j < n; j++) {
			cin >> mtrx[i][j];
		}
	}
	cout << endl;
	
	// Largest number in each row
	for (int i = 0; i < n; i++) {
		int max = 0;
		for (int j = 0; j < n; j++) {
			if (mtrx[i][j] > max) {
				max = mtrx[i][j];
			}
		}
		cout << "Largest number in row " << i+1 << " = " << max << endl;
	}
	cout << endl;
	
	// Largest number in each column
	for (int j = 0; j < n; j++) {
		int max = 0;
		for (int i = 0; i < n; i++) {
			if (mtrx[i][j] > max) {
				max = mtrx[i][j];
			}
		}
		cout << "Largest number in col " << j+1 << " = " << max << endl;
	}
	cout << endl;
	
	return 0;
}
