#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

const int range = 100001;
int v[100001] = { 0, };
int n, k;

void bfs() {
	queue<pair<int, vector<int>>> q;
	q.push({ n, {n}});
	v[n] = 0;

	while (!q.empty()) {
		pair<int, vector<int>> pos = q.front(); q.pop();
		int cx = pos.first;
		vector<int> cp = pos.second;
		if (cx == k) {
			cout << v[k] << "\n";
			for (int i : cp) {
				cout << i << " ";
			}
			return;
		}
		int nxs[3] = {cx - 1, cx + 1, cx * 2};
		for (int nx : nxs) {
			if (0 <= nx && nx < range && !v[nx]) {
				v[nx] = v[cx] + 1;
				cp.push_back(nx);
				q.push({ nx, cp });
				cp.pop_back();
			}
		}
	}
}

int main() {
	cin >> n >> k;
	if (n > k) {
		cout << n - k << "\n";
		for (int i = n; i >= k; i--) {
			cout << i << " ";
		}
	}
	else bfs();
}
