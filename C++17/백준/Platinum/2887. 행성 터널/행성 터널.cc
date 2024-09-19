#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

int n;
int nodes[100001];

struct Pos {
	int pos, idx;
	bool operator<(const Pos& other) const {
		return pos < other.pos;
	}
};

struct Edge {
	int w, n1, n2;
	bool operator<(const Edge& other) const {
		return w < other.w;
	}
};

vector<Pos> PI[3];

int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

bool Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A == B) return false;
	nodes[B] = A;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		nodes[i] = i;
		int x, y, z; cin >> x >> y >> z;
		PI[0].push_back({ x, i });
		PI[1].push_back({ y, i });
		PI[2].push_back({ z, i });
	}

	for (int i = 0; i < 3; i++) sort(PI[i].begin(), PI[i].end());

	vector<Edge> edges;
	for (int i = 0; i < n - 1; i++) {
		edges.push_back({ abs(PI[0][i].pos - PI[0][i + 1].pos), PI[0][i].idx, PI[0][i + 1].idx });
		edges.push_back({ abs(PI[1][i].pos - PI[1][i + 1].pos), PI[1][i].idx, PI[1][i + 1].idx });
		edges.push_back({ abs(PI[2][i].pos - PI[2][i + 1].pos), PI[2][i].idx, PI[2][i + 1].idx });
	}

	sort(edges.begin(), edges.end());
	int sum = 0;
	for (Edge edge:edges) {
		int w = edge.w, n1 = edge.n1, n2 = edge.n2;
		if (Union(n1, n2)) sum += w;
	}
	cout << sum;
}