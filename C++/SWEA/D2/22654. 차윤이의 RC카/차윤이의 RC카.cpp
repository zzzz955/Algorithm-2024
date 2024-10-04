#include<iostream>

using namespace std;
int tc, n, q, sx, sy, ex, ey;
string lst[5];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
		for (int j = 0; j < n; j++) {
			if (lst[i][j] == 'X') sx = i, sy = j;
			else if (lst[i][j] == 'Y') ex = i, ey = j;
		}
	}
	cin >> q;
}

void solution() {
	while (q--) {
		int l; string s;
		cin >> l >> s;
		int cx = sx, cy = sy, cd = 0;
		for (int i = 0; i < l; i++) {
			if (s[i] == 'R') cd = (cd + 5) % 4;
			else if (s[i] == 'L') cd = (cd + 3) % 4;
			else {
				int nx = cx + dx[cd], ny = cy + dy[cd];
				if (0 <= nx && nx < n && 0 <= ny && ny < n && lst[nx][ny] != 'T') cx = nx, cy = ny;
			}
		}
		if (cx == ex && cy == ey) cout << " 1";
		else cout << " 0";
	}
	cout << "\n";
}

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "#" << t;
		input();
		solution();
	}
}