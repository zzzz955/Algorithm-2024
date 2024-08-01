#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int v[101] = { 0, };
int ladder[101] = { 0, };
int snake[101] = { 0, };

struct pos {
	int x, time;
};

void bfs(int row) {
	queue<pos> q;
	q.push({ row, 0 });
	v[row] = 1;

	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		int x = now.x, time = now.time;
		if (x == 100) {
			cout << time;
			return;
		}
		for (int i = 1; i < 7; i++) {
			int nrow = x + i;
			if (nrow < 101 && !v[nrow]) {
				v[nrow] = 1;
				if (ladder[nrow]) {
					if (v[ladder[nrow]]) continue;
					v[ladder[nrow]] = 1;
					q.push({ ladder[nrow], time + 1 });
				}
				else if (snake[nrow]){
					if (v[snake[nrow]]) continue;
					v[snake[nrow]] = 1;
					q.push({ snake[nrow], time + 1 });
				}
				else {
					q.push({ nrow, time + 1 });
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a] = b;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		snake[a] = b;
	}
	bfs(1);
}