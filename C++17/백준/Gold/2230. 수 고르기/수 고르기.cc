#include<iostream>
#include<algorithm>
using namespace std;

int n, m, ans = 2e9;
int lst[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> lst[i];
	sort(lst, lst + n);

	int l = 0, r = 0;
	while (l < n - 1) {
		int diff = lst[r] - lst[l];
		if (diff >= m) {
			ans = min(ans, diff);
			l++;
		}
		else r++;
	}
	cout << ans;
}