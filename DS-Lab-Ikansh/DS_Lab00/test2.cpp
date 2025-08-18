// Given a string, find and display its biggest word (No punctuation)
#include <bits/stdc++.h>
using namespace std;

string input(string prompt)
{
	string s;
	cout << prompt;
	getline(cin, s);
	return s;
}


int main(void) {
	string s = input("Enter a string: ");
	vector<string> v(10, "");
	for (int i = 0, j = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			v[j] += s[i];
		} else j++;
	}
	
	int max_size = 0; string big = "";
	int min_size = v[0].size(); string small = v[0];
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
		if ((*it).size() > max_size) {
			max_size = (*it).size();
			big = (*it);
		}
		if ((*it).size() < min_size) {
			min_size = (*it).size();
			small = (*it);
		}
	}
	
	cout << big << endl;
	cout << small << endl;
}
