#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<ctype.h>
using namespace std;

int n;
int v[125];

string preprocess(string& str, int index) {
	string front = string(str.begin(), str.begin() + index);
	string mid = "[" + string(str.begin() + index, str.begin() + index + 1) + "]";
	string last = string(str.begin() + index + 1, str.end());
	return front + mid + last;
}

int main() {
	v[32] = 1;
	cin >> n;
	cin.get();

	vector<string> ans;
	for (int i = 0; i < n; i++) {
		string temp;
		getline(cin, temp);
		stringstream ss(temp);
		string s = "";
		int flag = 1;
		while (getline(ss, temp, ' ')) {
			if (flag && !v[tolower(temp[0])]) {
				v[tolower(temp[0])]++;
				flag = 0;
				temp = preprocess(temp, 0);
			}
			s += temp + ' ';
		}
		if (flag) {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == ' ') continue;
				if (!v[tolower(s[i])]) {
					v[tolower(s[i])]++;
					s = preprocess(s, i);
					break;
				}
			}
		}
		ans.push_back(s);
	}
	for (string a : ans) cout << a << "\n";
}