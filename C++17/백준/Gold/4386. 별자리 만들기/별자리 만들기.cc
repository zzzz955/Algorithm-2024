#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

int nodes[101];
int n;

vector<pair<int, int>> lst;

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
	cin >> n;
	for (int i = 0; i < n; i++) {
		float x, y;
		cin >> x >> y;
		lst.push_back({ x, y });
	}

	vector<tuple<float, int, int>> edges;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			float x1 = lst[i].first, y1 = lst[i].second;
			float x2 = lst[j].first, y2 = lst[j].second;
			float dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
			edges.push_back({ dist, i, j });
		}
	}
	sort(edges.begin(), edges.end());

	for (int i = 1; i <= n; i++) {
		nodes[i] = i;
	}

	float sum = 0;
	for (int i = 0; i < edges.size(); i++) {
		tuple<float, int, int> cur = edges[i];
		if (Find(get<1>(cur)) == Find(get<2>(cur))) continue;
		Union(get<1>(cur), get<2>(cur));
		sum += get<0>(cur);
	}
	printf("%.2f", sum);
}