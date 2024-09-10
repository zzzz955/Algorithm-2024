#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int tc, n, m, dest;
vector<vector<int>> path;
vector<int> cnt, sum;
int times[1001];

void input() {
	cin >> n >> m;
	path.assign(n + 1, vector<int>());
	cnt.assign(n + 1, 0);
	sum.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> times[i];
	while (m--) {
		int a, b; cin >> a >> b;
		path[a].push_back(b);
	}
	cin >> dest;
}

int solution() {	
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
		input();
		cout << solution() << "\n";
	}
}