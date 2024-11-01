#include<iostream>
#include<algorithm>
using namespace std;

int n, ans;
int nodes[2000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> nodes[i];

	sort(nodes, nodes + n);
	for (int i = 0; i < n; i++) {
		int l = 0, r = n - 1;
		while (l < r) {
			if (l == i) {
				l++;
				continue;
			}
			else if (r == i) {
				r--;
				continue;
			}

			if (nodes[l] + nodes[r] == nodes[i]) {
				ans++;
				break;
			}
			else if (nodes[l] + nodes[r] > nodes[i]) r--;
			else l++;
		}
	}
	cout << ans;
}