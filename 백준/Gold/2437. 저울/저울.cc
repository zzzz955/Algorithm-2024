#include<iostream>
#include<algorithm>
using namespace std;

int n;
int lst[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> lst[i];
	sort(lst, lst + n);

	int ans = 1;
	for (int i = 0; i < n; ++i) {
		if (lst[i] <= ans) ans += lst[i];
	}
	cout << ans;
}