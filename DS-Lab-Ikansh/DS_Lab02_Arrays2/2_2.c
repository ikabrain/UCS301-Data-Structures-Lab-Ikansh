#include <stdio.h>

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = n-1; i > 0; i--)
	{
		int swapped = 0;
		for (j = 0; j < i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}

int main(void)
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	bubbleSort(arr, n);
	
	printf("Sorted array:-\n");
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	return 0;
}
