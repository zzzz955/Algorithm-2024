#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;

int n, m, sum;
map<string, vector<string>> dic;
map<string, int> cnt;
map<string, set<string>> result;
queue<string> q;
set<string> sizo;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		dic[s] = {};
		cnt[s] = 0;
		result[s] = {};
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		string a, b; cin >> a >> b;
		dic[b].push_back(a);
	}
}

void solution() {
	for (const auto& d : dic) {
		for (const string& s : d.second) cnt[s]++;
	}

	for (const auto& c : cnt) {
		if (!c.second) {
			sum++;
			sizo.insert(c.first);
			q.push({ c.first });
		}
	}

	while (!q.empty()) {
		string cur = q.front(); q.pop();
		for (const string& s : dic[cur]) {
			if (!--cnt[s]) {
				q.push(s);
				result[cur].insert(s);
			}
		}
	}
}

void output() {
	cout << sum << "\n";
	for (const string& s : sizo) cout << s << " ";
	cout << "\n";

	for (const auto r : result) {
		cout << r.first;
		cout << " " << r.second.size();
		for (const string& s : r.second) cout << " " << s;
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	output();
}