#include<iostream>
#include<vector>

using namespace std;
int n;
vector<vector<int>> lst;
int dp[1000001][2];
int v[1000001];

void dfs(int cn) {
	dp[cn][0] = 0;
	dp[cn][1] = 1;
	for (int nn : lst[cn]) {
		if (v[nn]) continue;
		v[nn] = 1;
		dfs(nn);
		dp[cn][0] += dp[nn][1];
		dp[cn][1] += min(dp[nn][0], dp[nn][1]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	lst.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int n1, n2; cin >> n1 >> n2;
		lst[n1].push_back(n2);
		lst[n2].push_back(n1);
	}
	v[1] = 1;
	dfs(1);
	cout << min(dp[1][0], dp[1][1]);
}