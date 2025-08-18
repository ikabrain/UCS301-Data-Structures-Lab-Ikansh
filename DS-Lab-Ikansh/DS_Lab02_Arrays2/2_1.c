#include <stdio.h>

int binarySearch(int arr[], int n, int num)
{
	int l = 0, h = n-1;
	while (l <= h)
	{
		int mid = (l+h) / 2;
		if (arr[mid] == num)
			return mid;
		else if (num < arr[mid])
			h = mid-1;
		else if (arr[mid] < num)
			l = mid+1;
	}
	return -1;	
}

int main(void)
{
	int n;
	printf("Enter size of sorted array: ");
	scanf("%d", &n);
	printf("Enter sorted array:         ");
	
	int arr[n];
	
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	int x;
	printf("Enter number to be searched: ");
	scanf("%d", &x);
	
	int index = binarySearch(arr, n, x);
	
	if (index < 0)
		printf("Element not found in array.\n");
	else
		printf("Element found at index %d.\n", index);
	
	return 0;
}
