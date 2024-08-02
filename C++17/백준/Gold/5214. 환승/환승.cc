#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, m;
vector<int> ans;

struct pos {
	int city, cnt, isnode;
};

int bfs(vector<vector<int>>& nodes, vector<int>& nv, vector<vector<int>>& hyper, vector<int>& hv) {
	queue<pos> q;
	q.push({ 1, 1, 0 });
	//nv[1] = 1;

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();
		int cn = cur.city, cnt = cur.cnt, h = cur.isnode;
		if (cn == n && h == 0) return cnt;
		if (h && !hv[cn]) {
			hv[cn] = 1;
			for (int hype : hyper[cn]) {
				if (nv[hype]) continue;
				q.push({ hype, cnt + 1, 0 });
			}
			continue;
		}
		if (!h && !nv[cn]) {
			nv[cn] = 1;
			for (int node : nodes[cn]) {
				if (hv[node]) continue;
				q.push({ node, cnt, 1 });
			}
			continue;
		}
	}
	return -1;
}

int main() {
	cin >> n >> k >> m;
	vector<vector<int>> nodes(n + 1);
	vector<vector<int>> hyper(m + 1);
	vector<int> nv(n + 1, 0);
	vector<int> hv(m + 1, 0);
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			hyper[i].push_back(a);
			nodes[a].push_back(i);
		}
	}
	cout << bfs(nodes, nv, hyper, hv);
}