#include<iostream>
#include<unordered_map>

using namespace std;
int tc, n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;
		unordered_map<string, int> dic;

		int cnt = 0;
		while (n--) {
			string s; cin >> s;
			dic[s] = 1;
		}

		while (m--) {
			string s; cin >> s;
			if (dic[s]) cnt++;
		}

		cout << "#" << t << " " << cnt << "\n";
	}
}