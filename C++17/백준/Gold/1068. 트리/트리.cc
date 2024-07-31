#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, e, rt, cnt;
vector<vector<int>> lst;
vector<int> v;

void dfs(int index) {
	if (lst[index].empty()) return;
	for (int i : lst[index]) {
		if (v[i]) continue;
		if (i == e) {
			if (lst[index].size() == 1) cnt++;
			continue;
		}
		if (lst[i].empty()) {
			cnt++;
			continue;
		}
		v[i] = 1;
		dfs(i);
		v[i] = 0;
	}
}

int main() {
	cin >> n;
	lst.resize(n);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> e;
		if (e == -1) rt = i;
		else lst[e].push_back(i);
	}
	cin >> e;
	lst[e].clear();
	v[rt] = 1;
	dfs(rt);
	cout << cnt;
}