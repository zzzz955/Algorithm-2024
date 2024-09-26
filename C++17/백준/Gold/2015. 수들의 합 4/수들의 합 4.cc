#include<iostream>
#include<unordered_map>
#define ll long long

using namespace std;

unordered_map<ll, int> dic;
ll total = 0, ans = 0;
int n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		total = total + a;
		if (total == k) ans++;
		ans += dic[total - k];
		dic[total]++;
	}
	cout << ans;
}