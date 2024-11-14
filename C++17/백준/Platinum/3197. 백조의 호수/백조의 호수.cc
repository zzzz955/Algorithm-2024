#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int r, c, idx, ans;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
string lst[1500];
int v[1500][1500];

struct Pos {
	int x, y, g;
};

vector<int> nodes(1, 0);
queue<Pos> ice;
Pos swan[3];

void input() {
	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		cin >> lst[i];
		for (int j = 0; j < c; ++j) {
			if (lst[i][j] == 'L') {
				idx++;
				swan[idx] = { i, j, idx };
				nodes.push_back(idx);
				v[i][j] = idx;
			}
		}
	}
}

int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

void Union(int a, int b) {
	//if (a < b) swap(a, b);
	int A = Find(a);
	int B = Find(b);
	if (A == B) return;
	nodes[B] = A;
}

void bfs(const Pos& pos) {
	queue<Pos> q;
	q.push(pos);

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, cg = pos.g;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < r && 0 <= ny && ny < c && Find(v[nx][ny]) != Find(cg)) {
				if (v[nx][ny] && lst[nx][ny] != 'X') Union(cg, v[nx][ny]);
				if (!v[nx][ny]) {
					if (lst[nx][ny] == 'X') ice.push({ nx, ny, cg });
					else q.push({ nx, ny, cg });
					v[nx][ny] = cg;
				}
			}
		}
	}
}

void init() {
	bfs(swan[1]);
	bfs(swan[2]);	

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (lst[i][j] == '.' && !v[i][j]) {
				idx++;
				nodes.push_back(idx);
				v[i][j] = idx;
				bfs({ i, j, idx });
			}
		}
	}
}

void melt() {
	ans++;
	queue<Pos> q;
	swap(q, ice);

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, cg = pos.g;
		lst[cx][cy] = '.';

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < r && 0 <= ny && ny < c && Find(v[nx][ny]) != Find(cg)) {
				if (v[nx][ny] && lst[nx][ny] != 'X') Union(cg, v[nx][ny]);
				if (!v[nx][ny]) {
					if (lst[nx][ny] == 'X') ice.push({ nx, ny, cg });
					else q.push({ nx, ny, cg });
					v[nx][ny] = cg;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	init();
	while (Find(1) != Find(2)) melt();
	cout << ans;
}