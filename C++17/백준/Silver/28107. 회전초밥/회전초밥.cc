#include<iostream>
#include<queue>
using namespace std;

int n, m;
int cnt[100001];
queue<int> q[200001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int c; cin >> c;
		while (c--) {
			int s; cin >> s;
			q[s].push(i);
		}
	}

	while (m--) {
		int s; cin >> s;
		if (!q[s].empty()) {
			cnt[q[s].front()]++;
			q[s].pop();
		}
	}

	for (int i = 1; i <= n; ++i) cout << cnt[i] << " ";
}