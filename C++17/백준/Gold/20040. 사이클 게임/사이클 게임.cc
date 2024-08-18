#include<iostream>

using namespace std;

int n, m;
int nodes[500001];

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

	cin >> n >> m;
	for (int i = 1; i <= n; i++) nodes[i] = i;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		if (Find(a) == Find(b)) {
			cout << i;
			return 0;
		}
		Union(a, b);
	}
	cout << 0;
	return 0;
}