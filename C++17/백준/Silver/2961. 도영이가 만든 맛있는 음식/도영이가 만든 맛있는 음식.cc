#include<iostream>

using namespace std;
int n, ans = 1e9;
int v[10], ing1[10], ing2[10];

void bt(int level, int val1, int val2) {
	if (level) ans = min(ans, abs(val2 - val1));
	if (level == n) return;	

	for (int i = 0; i < n; i++) {
		if (v[i]) continue;
		v[i] = 1;
		bt(level + 1, val1 * ing1[i], val2 + ing2[i]);
		v[i] = 0;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ing1[i];
		cin >> ing2[i];
	}
	bt(0, 1, 0);
	cout << ans;
}