#include<iostream>
#define ll unsigned long long

using namespace std;

ll n, m, mt;
ll lst[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (ll i = 0; i < n; i++) {
		cin >> lst[i];
		mt = max(mt, lst[i]);
	}

	ll l = 1;
	ll r = 1e19;
	ll ans = 1e19;

	while (l <= r) {
		ll mid = (l + r) / 2;
		ll total = 0;

		for (ll i = 0; i < n; i++) {
			total += mid / lst[i];
		}

		if (total < m) l = mid + 1;
		else {
			ans = min(ans, mid);
			r = mid - 1;
		}
	}

	cout << ans;
}