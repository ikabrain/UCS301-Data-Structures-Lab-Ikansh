// A tridiagonal matrix is a square matrix with non-zero elements only on the main diagonal, the subdiagonal below, and the superdiagonal above.
// Basically, |j-i| <= 1
// For array with tri-diagonal matrix, we can use 3 arrays! 1. i,i 2. i,i+1 3. i,i-1!!!
#include <stdio.h>
// INCOMPLETE
void displayDiag(int diag[], int n)
{
	printf("\n");
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				printf(" %d ", diag[i]);
			}
			else
			{
				printf(" 0 ");
			}
		}
		printf("\n");
	}
}

int main(void)
{
	int n;
	printf("Enter size of square diagonal matrix: ");
	scanf("%d", &n);
	
	int diag[n];
	printf("Enter diagonal elements: ");
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &diag[i]);
	}
	
	printf("\nDiagonal matrix is:-");
	displayDiag(diag, n);
	
	return 0;
}
