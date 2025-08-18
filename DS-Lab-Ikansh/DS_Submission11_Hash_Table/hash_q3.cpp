#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T>
vector<int> findMissing(T arr1[], int n1, T arr2[], int n2)
{
	// Returns indices of elements in arr1 that are not in arr2
	vector<int> ind;
	
	// Hash arr2[], if at index = element of arr1, no element of arr2 is present, then append!
	unordered_map<T, int> hsh;
	for (int i = 0; i < n2; i++)
	{
		hsh[arr2[i]] = i;	
	}
	
	for (int i = 0; i < n1; i++)
	{
		// Find arr1[i] in the hash map
		auto it = hsh.find(arr1[i]);
		if (it == hsh.end())
		{
			// If element not found, then append!
			ind.push_back(arr1[i]);
		}
	}
	
	return ind;
}

int main(void)
{
	int n1;
	cout << "Enter number of elements in array 1: ";
	cin >> n1;
	int arr1[n1];
	cout << "Enter the array 1 elements: ";
	for (int i = 0; i < n1; i++)
	{
		int x;
		cin >> x;
		arr1[i] = x;
	}
	
	int n2;
	cout << "Enter number of elements in array 2: ";
	cin >> n2;
	int arr2[n2];
	cout << "Enter the array 2 elements: ";
	for (int i = 0; i < n2; i++)
	{
		int x;
		cin >> x;
		arr2[i] = x;
	}
	
	vector<int> res = findMissing(arr1, n1, arr2, n2);
	cout << endl << "Elements of array 1 not in 2 is/are: ";
	for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
		
	return 0;
}
