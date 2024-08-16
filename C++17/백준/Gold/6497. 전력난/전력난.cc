#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m;
int nodes[200001];

int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

void Union(int a, int b) {
	int rootA = Find(a);
	int rootB = Find(b);
	if (rootA == rootB) return;
	nodes[rootB] = rootA;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> ans;
	vector<tuple<int, int, int>> edges;
	int max_dist;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		
		max_dist = 0;
		edges.clear();
		memset(nodes, 0, sizeof(nodes));
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			edges.push_back({ c, a, b });
			max_dist += c;
		}

		sort(edges.begin(), edges.end());

		for (int i = 1; i <= n; i++) {
			nodes[i] = i;
		}

		int sum = 0;
		for (int i = 0; i < m; i++) {
			tuple<int, int, int> cur = edges[i];
			if (Find(get<1>(cur)) == Find(get<2>(cur))) continue;
			Union(get<1>(cur), get<2>(cur));
			sum += get<0>(cur);
		}
		ans.push_back(max_dist - sum);
	}
	for (int an : ans) cout << an << "\n";
}