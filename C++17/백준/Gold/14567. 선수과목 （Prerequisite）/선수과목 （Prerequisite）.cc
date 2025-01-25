#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 1001;
int n, m;
int result[N];
vector<int> lst[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		lst[a].push_back(b);
	}

	vector<int> cnt(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		for (int j : lst[i]) cnt[j]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (!cnt[i]) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		result[cur]++;
		for (int i : lst[cur]) {
			if (!--cnt[i]) {
				q.push(i);
				if (result[i] < result[cur]) result[i] = result[cur];
			}
		}
	}

	for (int i = 1; i <= n; ++i) cout << result[i] << " ";
}