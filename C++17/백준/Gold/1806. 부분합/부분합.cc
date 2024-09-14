#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, d, ans = 1e9;
int lst[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d;
	for (int i = 0; i < n; i++) cin >> lst[i];
	int s = 0, e = 0, sum = lst[0];
	while (s <= e && e < n) {
		if (sum >= d) {
			ans = min(ans, e - s + 1);
			sum -= lst[s];
			s++;
		}
		else {
			e++;
			sum += lst[e];
		}
	}
	if (ans == 1e9) cout << 0;
	else cout << ans;
}