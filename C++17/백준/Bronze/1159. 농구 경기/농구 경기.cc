#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	map<char, int> dic;
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (dic[s[0]]) dic[s[0]]++;
		else dic[s[0]] = 1;
	}
	string ans = "";
	for (auto it = dic.begin(); it != dic.end(); it++) {
		if (it->second >= 5) ans += it->first;
	}
	if (ans.empty()) cout << "PREDAJA";
	else cout << ans;
}