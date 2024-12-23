#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int t, n;
double e;
int nodes[1001];
struct Pos {
	int x, y;
};
Pos poses[1001];
struct Edge {
	int sn, dn;
	double w;
	bool operator<(const Edge& other) const {
		if (w == other.w) return sn < other.sn;
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
	if (A == B) return false;
	nodes[B] = A;
	return true;
}

double getdist(const Pos& pos1, const Pos& pos2) {
	return e * (pow(abs(pos1.x - pos2.x), 2) + pow(abs(pos1.y - pos2.y), 2));
}

int main() {
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> poses[i].x;
		for (int i = 1; i <= n; ++i) cin >> poses[i].y;

		cin >> e;
		vector<Edge> edges;
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				const Pos& pos1 = poses[i], pos2 = poses[j];
				double dist = getdist(pos1, pos2);
				edges.push_back({ i, j, dist });
			}
		}
		sort(edges.begin(), edges.end());

		for (int i = 1; i <= n; ++i) nodes[i] = i;
		double sum = 0;
		for (const Edge& edge : edges) {
			int A = edge.sn, B = edge.dn;
			double w = edge.w;
			if (Union(A, B)) sum += w;
		}
		cout << "#" << tc << " " << (long long)round(sum) << "\n";
	}
}