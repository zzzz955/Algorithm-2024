#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n;
int v[10001];
struct Edge {
	int nxt, val;
};
vector<vector<Edge>> lst;
pair<int, int> result;

void dfs(int node, int val) {
	if (result.second < val) result = { node, val };
	for (const Edge& edge : lst[node]) {
		if (!v[edge.nxt]) {
			v[edge.nxt] = 1;
			dfs(edge.nxt, val + edge.val);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	lst.resize(n + 1);
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c; cin >> a >> b >> c;
		lst[a].push_back({ b, c });
		lst[b].push_back({ a, c });
	}

	v[1] = 1;
	dfs(1, 0);

	memset(v, 0, sizeof(v));
	v[result.first] = 1;
	dfs(result.first, 0);

	cout << result.second;
}