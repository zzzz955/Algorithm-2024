#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int tc, n, k;

int main() {
	cin >> tc;
	for (int c = 1; c <= tc; c++) {
		string s;
		cin >> n >> k >> s;
		vector<int> lst;
		for (int i = 0; i < n; i++) {
			string temp = s.substr(0, n / 4);
			int convert = stoi(temp, nullptr, 16);
			if (find(lst.begin(), lst.end(), convert) == lst.end()) lst.push_back(convert);
			s = s.substr(1, n - 1) + s[0];
		}
		sort(lst.begin(), lst.end(), greater<int>());
		cout << "#" << c << " " << lst[k - 1] << "\n";
	}
}