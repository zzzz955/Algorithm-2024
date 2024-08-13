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

	cin >> n;

	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int c;
			cin >> c;
			if (j >= i && c) edges.push_back({ c, i, j });
		}
	}
	sort(edges.begin(), edges.end());

	for (int i = 1; i <= n; i++) {
		nodes[i] = i;
	}

	long long sum = 0;
	for (int i = 0; i < edges.size(); i++) {
		tuple<int, int, int> cur = edges[i];
		if (Find(get<1>(cur)) == Find(get<2>(cur))) continue;
		Union(get<1>(cur), get<2>(cur));
		sum += get<0>(cur);
	}
	cout << sum;
}