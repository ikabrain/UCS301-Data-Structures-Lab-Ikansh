#include <stdio.h>

#define MAX 100

// USES HASHING => T.C. = O(n), S.C. = O(n)
void removeDuplicates(int arr[], int *n)
{
	int hash[MAX] = {0}, temp[*n]; // All entries of hash[] are now 0!
	int i, j = 0;
	for (i = 0, j = 0; i < *n; i++)
	{
		hash[arr[i]]++;
		// If first occurence of unique element, append to temp[]
		if (hash[arr[i]] == 1)
		{
			temp[j] = arr[i];
			j++;
		}
	}
	
	for (i = 0; i < j; i++)
	{
		arr[i] = temp[i];
	}
	
	*n = j;
}

int main(void)
{
	int i, n;
	scanf("%d", &n);
	int arr[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	removeDuplicates(arr, &n);
	
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
