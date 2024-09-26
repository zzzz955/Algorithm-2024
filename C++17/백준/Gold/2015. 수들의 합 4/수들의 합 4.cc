#include<iostream>
#include<unordered_map>
#define ll long long

using namespace std;

unordered_map<ll, int> dic;
ll sum[200001] = { 0, };
ll n, k, ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	for (int i = 1; i <= n; i++) {
		if (sum[i] == k) ans++;
		ans += dic[sum[i] - k];
		dic[sum[i]]++;
	}
	cout << ans;
}