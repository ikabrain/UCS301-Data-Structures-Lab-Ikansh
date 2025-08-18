#include <stdio.h>

// BRUTE:-
void missingElements(int arr[], int size)
{ 
    int diff = arr[0] - 0;
    int i;
    for (i = 0; i < size; i++) {  
        if (arr[i] - i != diff) {
            while (diff < arr[i] - i) { 
                printf("%d ", i + diff);
                diff++; 
            } 
        } 
    } 
} 


int main(void)
{
	int a[] = {1, 2, 6};
	missingElements(a, sizeof(a)/sizeof(int));
	return 0;
}
