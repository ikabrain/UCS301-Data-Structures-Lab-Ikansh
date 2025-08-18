#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

pair<int, int> twoSum(int arr[], int n, int x)
{
	// Hash, and check if x - current_elem exists. If yes, then return the pair!
	// To make it easier to return index of x-curr, instead of storing freq, use hash map to store index!!!
	unordered_map<int, int> hsh;
	for (int i = 0; i < n; i++)
	{
		hsh[arr[i]] = i;
		// Use find() iterator in the unordered map!
		if (hsh.find(x - arr[i]) != hsh.end())
		{
			return {hsh[x - arr[i]], i};
		}
	}
	return {-1, -1};
}

int main(void)
{
	int n;
	cout << "Enter number of elements in array: ";
	cin >> n;
	int a[n];
	cout << "Enter the array elements: ";
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a[i] = x;
	}
	int x;
	cout << "Enter sum value: ";
	cin >> x; 
	
	// Returns the indices of 2 elements that add up to x!
	pair<int, int> ind = twoSum(a, n, x);
	if (ind.first == -1 || ind.second == -1)
	{
		cout << "No two elements found in array whose sum is exactly " << x << "." << endl;
	}
	else
	{
		cout << "Elements " << a[ind.first] << " and " << a[ind.second] << " in the array add up to " << x << "!" << endl;
	}
	
	return 0;
}
