#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

int t;
int sosu[10000];
string s, e;
struct Cur {
	string str;
	int c;
};
unordered_map<string, bool> dic;

int bfs() {
	queue<Cur> q;
	q.push({ s, 0 });
	unordered_map<string, bool> v;
	v[s] = true;

	while (!q.empty()) {
		Cur cur = q.front(); q.pop();
		string str = cur.str;
		int cc = cur.c;
		if (str == e) return cc;

		for (int i = 0; i < 4; ++i) {
			for (char j = '0'; j <= '9'; ++j) {
				string nstr = str;
				nstr[i] = j;
				if (!dic[nstr] || v[nstr]) continue;
				v[nstr] = true;
				q.push({ nstr, cc + 1 });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 2; i * i < 10000; ++i) {
		if (!sosu[i]) {
			for (int j = i * i; j < 10000; j += i) sosu[j] = 1;
		}
	}

	for (int i = 1000; i < 10000; ++i) {
		if (!sosu[i]) dic[to_string(i)] = true;
	}

	cin >> t;
	while (t--) {
		cin >> s >> e;
		int result = bfs();
		if (result == -1) cout << "Impossible\n";
		else cout << result << "\n";
	}
}