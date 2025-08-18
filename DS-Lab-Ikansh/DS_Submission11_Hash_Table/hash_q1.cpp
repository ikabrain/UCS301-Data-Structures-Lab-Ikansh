#include <iostream>
#include <unordered_map>
using namespace std;

template <typename T>
int mostFrequent(T arr, int n)
{
	// Hash frequency of all array elements
	unordered_map <T, int> hsh;
	int maxi = 0;
	for (int i = 0; i < n; i++)
	{
		hsh[arr[i]]++;
		// Check if element of array has maximum frequency!
		if (hsh[arr[i]] > arr[maxi])
		{
			maxi = i;
		}
	}
	
	return maxi;
}

int main(void)
{
	int n;
	cout << "Enter number of elements in array: ";
	cin >> n;
	int arr[n];
	cout << "Enter the array elements: ";
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr[i] = x;
	}
	
	int res = mostFrequent(arr, n);
	cout << endl << "Most frequent element in the array is " << arr[res] << "." << endl;
	
	return 0;
}
