// For a user-input square matrix, find out the number which is LARGEST in its row BUT SMALLEST in its column!!!

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
	
	// Checking if elem is largest in row, then seeing if its smallest in its col!
	int final = -1;
	for (int i = 0; i < n; i++) {
		int elem = 0, col = 0;
		for (int j = 0; j < n; j++) {
			if (mtrx[i][j] > elem) {
				elem = mtrx[i][j];
				col = j;
			}
		}
		
		int flag = 1;
		
		for (int k = 0; k < n; k++) {
			if (elem > mtrx[k][col]) {
				flag = 0;
				break;
			}
		}
		
		if (flag) {
			final = elem;
			break;
		}
	}
	
	if (final == -1) {
		cout << "No element satisfying this criterion.\n";
	} else {
		cout << "Element satisfying this crierion = " << final << endl;	
	}
	
	return 0;
}
