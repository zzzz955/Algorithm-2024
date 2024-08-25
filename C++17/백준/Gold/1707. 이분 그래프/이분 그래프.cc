#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> nodes[20001];
int color[20001];
int k, v, e;

bool bfs(int sn) {
	queue<int> q;
	q.push(sn);
	color[sn] = 1;

	while (!q.empty()) {
		int cn = q.front(); q.pop();
		for (int nn : nodes[cn]) {
			if (!color[nn]) {
				color[nn] = 3 - color[cn];
				q.push(nn);
			}
			else if (color[nn] == color[cn]) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	while (k--) {
		cin >> v >> e;
		for (int i = 1; i <= v; i++) {
			nodes[i].clear();
			color[i] = 0;
		}
		
		while (e--) {
			int a, b; cin >> a >> b;
			nodes[a].push_back(b);
			nodes[b].push_back(a);
		}

		int flag = 0;
		for (int i = 1; i <= v; i++) {
			if (!color[i]) {
				if (!bfs(i)) {
					flag = 1;
					break;
				}
			}
		}
		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}
}