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
	cin >> n >> m;

	long long max_sum = 0;
	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edges.push_back({ c, a, b });
		max_sum += c;
	}
	sort(edges.begin(), edges.end());

	for (int i = 1; i <= n; i++) {
		nodes[i] = i;
	}

	long long sum = 0, sum_cnt = 0;
	for (int i = 0; i < m; i++) {
		tuple<int, int, int> cur = edges[i];
		if (Find(get<1>(cur)) == Find(get<2>(cur))) continue;
		Union(get<1>(cur), get<2>(cur));
		sum += get<0>(cur);
		sum_cnt++;
	}
	if (sum_cnt == n - 1) cout << max_sum - sum;
	else cout << -1;
}