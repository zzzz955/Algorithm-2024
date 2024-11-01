#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n;
int lst[101];
int v[101];
vector<int> ans;

void dfs(int s, int e) {
	if (v[e]) {
		if (s == e) ans.push_back(e);
		return;
	}

	v[e] = 1;
	dfs(s, lst[e]);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> lst[i];
	for (int i = 1; i <= n; i++) {
		memset(v, 0, sizeof(v));
		dfs(i, i);
	}

	cout << ans.size() << "\n";
	for (int i : ans) cout << i << "\n";
}