#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string s;
	vector<char> a = {'a', 'e', 'i', 'o', 'u'};
	int cnt = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (find(a.begin(), a.end(), s[i]) != a.end()) cnt++;
	}
	cout << cnt;
}