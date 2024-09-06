#include<iostream>
#define ll long long

using namespace std;
int tc, n, Move, Stay;
ll ans;

struct Pos {
	int x, y;
};

Pos pos[21];

void init() {
	ans = 9e15;
	Move = 0;
	Stay = 0;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> pos[i].x >> pos[i].y;
}

void dfs(int level, ll sumX, ll sumY) {
	if (Move == n / 2 && Stay == n / 2) {
		ans = min(ans, sumX * sumX + sumY * sumY);
		return;
	}

	if (n / 2 > Move) {
		Move++;
		dfs(level + 1, sumX + pos[level].x, sumY + pos[level].y);
		Move--;
	}

	if (n / 2 > Stay) {
		Stay++;
		dfs(level + 1, sumX - pos[level].x, sumY - pos[level].y);
		Stay--;
	}
	return;
}

void solution() {
	dfs(0, 0, 0);
}

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();
		input();
		solution();
		cout << "#" << t <<" " << ans << "\n";
	}
}