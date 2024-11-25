#include<iostream>
#include<sstream>
#include<unordered_map>
#include<queue>
#include<string>
#define pii pair<int, int>
using namespace std;
int n;
int idx[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<string, pii> dic;
	cin >> n;
	cin.get();
	for (int i = 1; i <= n; ++i) {
		int index = 0;
		string s;
		getline(cin, s);
		stringstream ss(s);
		while (getline(ss, s, ' ')) dic[s] = { i, index++ };
	}

	string s;
	getline(cin, s);
	stringstream ss(s);
	queue<string> q;
	while (getline(ss, s, ' ')) {
		if (!dic[s].first) {
			cout << "Impossible";
			return 0;
		}

		pii d = dic[s];
		if (d.second == idx[d.first]) {
			idx[d.first]++;
			dic.erase(s);
		}
		else {
			cout << "Impossible";
			return 0;
		}
	}

	int flag = 1;
	for (const auto& d : dic) if (d.second.first) flag = 0;
	if (flag) cout << "Possible";
	else cout << "Impossible";
}