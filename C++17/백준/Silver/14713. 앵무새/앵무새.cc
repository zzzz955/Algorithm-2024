#include<iostream>
#include<sstream>
#include<unordered_map>
#include<string>
#define pii pair<int, int>
using namespace std;
int n;
int idx[101];
string s;
unordered_map<string, pii> dic;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; cin.get();
	for (int i = 1; i <= n; ++i) {
		int index = 0;
		getline(cin, s);
		stringstream ss(s);
		while (getline(ss, s, ' ')) dic[s] = { i, index++ };
	}

	getline(cin, s);
	stringstream ss(s);
	while (getline(ss, s, ' ')) {
		if (!dic[s].first || dic[s].second != idx[dic[s].first]) {
			cout << "Impossible";
			return 0;
		}
		else {
			idx[dic[s].first]++;
			dic.erase(s);
		}
	}

	if (!dic.size()) cout << "Possible";
	else cout << "Impossible";
}