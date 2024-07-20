#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;
	vector<string> lst;
	for (int i = 0; i < s.size(); i++) {
		string temp = "";
		for (int j = i; j < s.size(); j++) {
			temp += s[j];
		}
		lst.push_back(temp);
	}
	sort(lst.begin(), lst.end());
	for (int i = 0; i < lst.size(); i++) {
		cout << lst[i] << "\n";
	}
}