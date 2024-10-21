#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n, m, l, ans = 1e9;
int lst[50];

int main() {
	cin >> n >> m >> l;
	for (int i = 0; i < n; i++) cin >> lst[i];
	sort(lst, lst + n);

	if (!n) ans = ceil((double)l / (m + 1));
	else {
		int left = 1, right = 2000;
		while (left <= right) {
			int mid = (left + right) / 2;
			int cur = 0;
			int install = 0;

			for (int i = 0; i < n; i++) {
				while (cur + mid < lst[i]) {
					cur += mid;
					install++;
				}
				cur = lst[i];
			}

			while (cur + mid < l) {
				cur += mid;
				install++;
			}

			if (install <= m) {
				right = mid - 1;
				ans = min(ans, mid);
			}
			else left = mid + 1;
		}
	}
	cout << ans;
}