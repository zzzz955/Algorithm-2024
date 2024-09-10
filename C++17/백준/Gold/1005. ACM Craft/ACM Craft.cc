#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int tc, n, m, dest;
vector<int> path[1001];
int times[1001];

void init() {
	memset(times, 0, sizeof(times));
	for (int i = 1; i < 1001; i++) path[i].clear();
}

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> times[i];
	while (m--) {
		int a, b; cin >> a >> b;
		path[a].push_back(b);
	}
	cin >> dest;
}

int solution() {
	vector<int> cnt(n + 1, 0);
	vector<int> sum(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		for (int node : path[i]) cnt[node]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!cnt[i]) {
			q.push(i);
			sum[i] = times[i];
		}
	}

	while (!q.empty()) {
		int node = q.front(); q.pop();
		
		for (int next : path[node]) {
			sum[next] = max(sum[next], sum[node] + times[next]);
			if (--cnt[next] == 0) q.push(next);
		}
	}

	return sum[dest];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		init();
		input();
		cout << solution() << "\n";
	}
}