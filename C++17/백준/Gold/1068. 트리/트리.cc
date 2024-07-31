#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, e, rt, cnt;
vector<vector<int>> lst;

void dfs(int index) {
	if (lst[index].empty()) return;
	for (int i : lst[index]) {
		if (i == e) {
			if (lst[index].size() == 1) cnt++;
			continue;
		}
		if (lst[i].empty()) {
			cnt++;
			continue;
		}
		dfs(i);
	}
}

int main() {
	cin >> n;
	lst.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> e;
		if (e == -1) rt = i;
		else lst[e].push_back(i);
	}
	cin >> e;
	lst[e].clear();
	dfs(rt);
	cout << cnt;
}