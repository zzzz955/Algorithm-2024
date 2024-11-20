#include<iostream>
#include<algorithm>
using namespace std;

int n, o, t, ans = 2e9;
int lst[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> lst[i];
	sort(lst, lst + n);

	int l = 0, r = n - 1;
	while (l < r) {
		int val = lst[l] + lst[r];
		if (abs(val) < abs(ans)) {
			ans = val;
			o = lst[l], t = lst[r];
		}

		if (val > 0) r--;
		else if (val < 0) l++;
		else break;
	}

	cout << o << " " << t;
}