#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int nodes[100001];
int n, m;

vector<tuple<int, int, int>> lst;

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
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edges.push_back({ c, a, b });
	}
	sort(edges.begin(), edges.end());

	for (int i = 1; i <= n; i++) {
		nodes[i] = i;
	}

	int sum = 0, max_val = 0;
	for (int i = 0; i < m; i++) {
		tuple<int, int, int> cur = edges[i];
		if (Find(get<1>(cur)) == Find(get<2>(cur))) continue;
		Union(get<1>(cur), get<2>(cur));
		sum += get<0>(cur);
		max_val = max(max_val, get<0>(cur));
	}
	cout << sum - max_val;
}