#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int n, m;
map<int, vector<int>> dic;
vector<bool> v;

void dfs(int index) {
	vector<int> stack;
	stack.push_back(index);
	while (stack.size()) {
		int node = stack.back();
		stack.pop_back();
		if (!v[node]) {
			v[node] = true;
			for (int i = 0; i < dic[node].size(); i++) {
				if (!v[dic[node][i]]) stack.push_back(dic[node][i]);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dic[a].push_back(b);
		dic[b].push_back(a);
	}
	int cnt = 0;
	v.resize(n + 1, false);
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
}