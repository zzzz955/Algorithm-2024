#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n, l, r, idx, ans;
int lst[50][50];
int v[50][50];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int x, y;
};

struct VC {
	int val, cnt;
};

VC vcs[2500];

void bfs(int sx, int sy, int idx) {
	queue<Pos> q;
	q.push({ sx, sy });
	v[sx][sy] = idx;
	vcs[idx].val += lst[sx][sy];
	vcs[idx].cnt++;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;
		
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && !v[nx][ny] && l <= abs(lst[cx][cy] - lst[nx][ny]) && abs(lst[cx][cy] - lst[nx][ny]) <= r) {
				v[nx][ny] = idx;
				vcs[idx].val += lst[nx][ny];
				vcs[idx].cnt++;
				q.push({ nx, ny });
			}
		}
	}
}

void input() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> lst[i][j];
		}
	}
}

void init() {
	idx = 1;
	memset(v, 0, sizeof(v));
	memset(vcs, 0, sizeof(vcs));
}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j]) continue;
			bfs(i, j, idx++);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			VC vc = vcs[v[i][j]];
			lst[i][j] = vc.val / vc.cnt;
		}
	}
}

//void print() {
//	cout << "\n";
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << lst[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	
//	cout << "\n";
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << v[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}

int main() {
	input();

	while (1) {
		init();
		solution();
		//print();

		if (idx == n * n + 1) break;
		else ans++;
	}
	cout << ans;
}