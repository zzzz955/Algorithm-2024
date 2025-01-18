#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, k;
int nodes[1001];
struct Edge {
	int cn, nn, w;
	bool operator<(const Edge& other) const {
		return w < other.w;
	}
};

int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

bool Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A > B) swap(A, B);
	if (A == B) return false;
	nodes[B] = A;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i < 1000; ++i) nodes[i] = i;
	
	vector<int> val;
	while (k--) {
		int a; cin >> a;
		val.push_back(a);
	}

	sort(val.begin(), val.end());
	for (int i = 1; i < val.size(); ++i) {
		nodes[val[i]] = val[0];
	}

	vector<Edge> edges;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		edges.push_back({ a, b, c });
	}

	sort(edges.begin(), edges.end());

	int sum = 0;
	for (const Edge& edge : edges) {
		if (Union(edge.cn, edge.nn)) sum += edge.w;
	}
	cout << sum;
}