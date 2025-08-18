#include <iostream>
#include <unordered_map>
#include <list>
#include <unordered_set>
using namespace std;

template <typename T>
list<T> getUnion(list<T> l1, list<T> l2)
{
	list<T> union_list;
	unordered_set<T> union_set;
	
	// Insert all unique elements of the union set into the list!
	for (auto it = l1.begin(); it != l1.end(); it++)
	{
		if (union_set.insert(*it).second)
		{
			union_list.push_back(*it);
		}
	}
	for (auto it = l2.begin(); it != l2.end(); it++)
	{
		if (union_set.insert(*it).second)
		{
			union_list.push_back(*it);
		}
	}
	
	return union_list;
}

template <typename T>
list<T> getIntersection(list<T> l1, list<T> l2)
{
	list<T> inter_list;
	unordered_set<T> inter_set;
	
	// Hash one of the lists, and check if element of second list is in the hash!
	unordered_map<T, int> hsh;
	for (auto it = l1.begin(); it != l1.end(); it++)
	{
		hsh[*it]++;
	}
	
	for (auto it = l2.begin(); it != l2.end(); it++)
	{
		if (hsh[*it] > 0 && inter_set.insert(*it).second)
		{
			inter_list.push_back(*it);
		}
	}
	
	return inter_list;
}

int main(void)
{
	list<int> ll1, ll2;
	cout << "Enter the contents of the first linked list (Type -99 to stop): ";
	while (true)
	{
		int x;
		cin >> x;
		if (x == -99) break;
		ll1.push_back(x);
	}
	cout << "Enter the contents of the second linked list (Type -99 to stop): ";
	while (true)
	{
		int y;
		cin >> y;
		if (y == -99) break;
		ll2.push_back(y);
	}
	
	list<int> un = getUnion(ll1, ll2);
	list<int> inter = getIntersection(ll1, ll2);
	
	cout << endl << "Union of the two lists is: ";
	for (auto it = un.begin(); it != un.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << "Intersection of the two lists is: ";
	for (auto it = inter.begin(); it != inter.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	return 0;
}
