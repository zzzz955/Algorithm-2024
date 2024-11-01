#include<iostream>
#include<algorithm>
using namespace std;

int n, ans1, ans2;

void toggle(string& f, int idx) {
	if (idx == n - 1) {
		f[idx - 1] = f[idx - 1] == '1' ? '0' : '1';
		f[idx] = f[idx] == '1' ? '0' : '1';
	}
	else {
		f[idx - 1] = f[idx - 1] == '1' ? '0' : '1';
		f[idx] = f[idx] == '1' ? '0' : '1';
		f[idx + 1] = f[idx + 1] == '1' ? '0' : '1';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string f1, f2, e;
	cin >> n >> f1 >> e;
	if (f1 == e) {
		cout << 0;
		return 0;
	}

	f2 = f1;
	f2[0] = f2[0] == '1' ? '0' : '1';
	f2[1] = f2[1] == '1' ? '0' : '1';
	ans2++;
	for (int i = 1; i < n; i++) {
		if (f1[i - 1] != e[i - 1]) {
			toggle(f1, i);
			ans1++;
		}
		if (f2[i - 1] != e[i - 1]) {
			toggle(f2, i);
			ans2++;
		}
	}

	if (f1 == e && f2 == e) cout << min(ans1, ans2);
	else if (f1 == e) cout << ans1;
	else if (f2 == e) cout << ans2;
	else cout << -1;
}