#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

set<pair<int, int>> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> lst;
	string s; getline(cin, s);
	int l;  cin >> l;
	stringstream ss = stringstream(s);
	while (getline(ss, s, ' ')) lst.push_back(stoi(s));
	
	int length = lst.size();
	sort(lst.begin(), lst.end());
	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (lst[i] + lst[j] == l) {
				ans.insert({ lst[i], lst[j] });
			}
		}
	}
	for (const auto& it : ans) cout << it.first << " " << it.second << "\n";
	cout << ans.size();
}