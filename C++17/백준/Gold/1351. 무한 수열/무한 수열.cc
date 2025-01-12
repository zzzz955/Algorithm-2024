#include<iostream>
#include<unordered_map>
#include<algorithm>
#define ll long long
using namespace std;

ll n, p, q;
unordered_map<ll, ll> dp;

ll solve(ll num) {
	if (dp[num]) return dp[num];
	dp[num] = solve(num / p) + solve(num / q);
	return dp[num];
}

int main() {
	cin >> n >> p >> q;
	dp[0] = 1;
	
	if (!n) cout << 1;
	else cout << solve(n / p) + solve(n / q);
}