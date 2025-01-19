#include<iostream>
using namespace std;

int n, m, ans = 10000;
int lst[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> lst[i];

	int l = 0, r = 10000;
	while (l <= r) {
		int mid = (l + r) / 2;

		int cnt = 1;
		int MAX = lst[0];
		int MIN = lst[0];
		int diff = MAX - MIN;
		for (int i = 1; i < n; ++i) {
			if (MAX < lst[i]) MAX = lst[i];
			else if (MIN > lst[i]) MIN = lst[i];

			diff = MAX - MIN;
			if (diff > mid) {
				cnt++;
				MAX = lst[i];
				MIN = lst[i];
				diff = MAX - MIN;
			}
		}

		if (cnt > m) l = mid + 1;
		else {
			ans = min(ans, mid);
			r = mid - 1;
		}
	}
	cout << ans;
}