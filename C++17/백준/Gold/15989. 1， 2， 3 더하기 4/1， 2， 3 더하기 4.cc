#include<iostream>

using namespace std;

int dp[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < 4; i++) dp[i] = i;
	for (int i = 4; i < 10001; i++) {
		dp[i] = dp[i - 3] + i / 2 + 1;
	}

	int t; cin >> t;
	while (t--) {
		int a; cin >> a;
		cout << dp[a] << "\n";
	}
}