// For array with diagonal matrix, A[i] = a_ii, 0 otherwise!
#include <stdio.h>

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
