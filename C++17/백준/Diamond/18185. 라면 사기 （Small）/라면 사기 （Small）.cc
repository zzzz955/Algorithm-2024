#include<iostream>
#include<algorithm>
using namespace std;

int n, ans;
int nodes[10002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> nodes[i];
	for (int i = 0; i < n; i++) {
		if (!nodes[i]) continue;
		if (nodes[i + 1] > nodes[i + 2]) {
			int common = min(nodes[i], nodes[i + 1] - nodes[i + 2]);
			ans += common * 5;
			nodes[i] -= common;
			nodes[i + 1] -= common;

			common = min({ nodes[i], nodes[i + 1], nodes[i + 2] });
			ans += common * 7;
			nodes[i] -= common;
			nodes[i + 1] -= common;
			nodes[i + 2] -= common;
		}
		else {
			int common = min({ nodes[i], nodes[i + 1], nodes[i + 2] });
			ans += common * 7;
			nodes[i] -= common;
			nodes[i + 1] -= common;
			nodes[i + 2] -= common;

			common = min(nodes[i], nodes[i + 1]);
			ans += common * 5;
			nodes[i] -= common;
			nodes[i + 1] -= common;
		}
		ans += nodes[i] * 3;
		nodes[i] = 0;
	}
	cout << ans;
}