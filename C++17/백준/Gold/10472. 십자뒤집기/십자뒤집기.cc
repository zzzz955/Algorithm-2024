#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int tc, target;
string lst[3];

int dx[] = { 0, 0, 0, 1, -1 };
int dy[] = { 0, 1, -1, 0, 0 };
int v[513];

struct Pos {
	int bits, cnt;
};

void getTarget() {
	target = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (lst[i][j] == '*') target += (1 << i * 3 + j);
		}
	}
}

int togle(int cx, int cy, int bits) {
	for (int i = 0; i < 5; i++) {
		int nx = cx + dx[i], ny = cy + dy[i];
		if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) bits ^= 1 << nx * 3 + ny;
	}
	return bits;
}

int solution() {
	queue<Pos> q;
	q.push({0, 0});
	memset(v, 0, sizeof(v));

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int val = pos.bits, cnt = pos.cnt;
		if (val == target) return cnt;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int new_val = togle(i, j, val);
				if (!v[new_val]) {
					v[new_val] = cnt + 1;
					q.push({ new_val, cnt + 1 });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		for (int i = 0; i < 3; i++) cin >> lst[i];
		getTarget();
		cout << solution() << "\n";
	}
}