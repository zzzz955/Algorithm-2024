#include<iostream>
#define ll long long

using namespace std;
ll n, k;

int main() {
	cin >> n >> k;
	ll left = 1, right = n * n, result = 0;

	while (left <= right) {
		ll mid = (left + right) / 2, cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}
		if (cnt >= k) {
			right = mid - 1;
			result = mid;
		}
		else left = mid + 1;
	}
	cout << left;
}