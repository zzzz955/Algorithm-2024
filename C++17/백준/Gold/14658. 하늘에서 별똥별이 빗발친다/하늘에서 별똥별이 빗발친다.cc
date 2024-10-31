#include<iostream>
#include<vector>
#include<set>
using namespace std;

int n, m, l, k, ans = 1e9;

struct Star {
	int x, y;
};

set<int> xdic;
set<int> ydic;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> l >> k;

	vector<Star> stars;
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		stars.push_back({ x, y });
		xdic.insert(x);
		ydic.insert(y);
	}

	int dx[] = { l, l, -l, -l };
	int dy[] = { -l, l, l, -l };
	for (int x : xdic) {
		for (int y : ydic) {
			int nx = x + l, ny = y + l;
			int cnt = 0;
			for (const Star& star : stars) {
				if (x <= star.x && star.x <= nx && y <= star.y && star.y <= ny) cnt++;
			}
			ans = min(ans, k - cnt);
		}
	}

	cout << ans;
}