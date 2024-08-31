#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m, d, ans;
vector<vector<int>> lst;
int v[15] = { 0, };

int dx[] = { 0, -1, 0};
int dy[] = { -1, 0, 1};

struct Pos {
	int x, y, move;
};

void input() {
	cin >> n >> m >> d;
	lst.resize(n, vector<int>(m, 0));
	ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lst[i][j];
		}
	}
}

void simulation(Pos archer, vector<vector<int>>& map, vector<Pos>& targets) {
	int visit[15][15] = { 0, };
	queue<Pos> simul;
	simul.push(archer);
	while (!simul.empty()) {
		Pos pos = simul.front(); simul.pop();
		int cx = pos.x, cy = pos.y, cm = pos.move;
		for (int i = 0; i < 3; i++) {
			int nx = cx + dx[i], ny = cy + dy[i], nm = cm + 1;
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !visit[nx][ny]) {
				visit[nx][ny] = 1;
				if (map[nx][ny] == 1) {
					targets.push_back({ nx, ny });
					return;
				}
				if (nm == d) continue;
				simul.push({ nx, ny, nm });
			}
		}
	}
}

void print(vector<vector<int>>& map) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int bfs(vector<Pos> col) {
	vector<vector<int>> map = lst;
	int distroy = 0;
	for (int i = 0; i < n; i++) {
		vector<Pos> Archer = col;
		vector<Pos> targets;
		for (int j = 0; j < 3; j++) {
			Pos archer = Archer[j];
			simulation(archer, map, targets);
		}
		for (Pos pos : targets) {
			if (map[pos.x][pos.y]) {
				map[pos.x][pos.y] = 0;
				distroy++;
			}
		}
		//print(map);
		for (int k = 0; k < m; k++) map[n - 1][k] = 0;
		for (int j = n - 1; j > 0; j--) {
			for (int k = 0; k < m; k++) {
				int temp = map[j][k];
				map[j][k] = map[j - 1][k];
				map[j - 1][k] = temp;
			}
		}
	}
	return distroy;
}

void dfs(int level, vector<Pos> col) {
	if (level == 3) {
		ans = max(ans, bfs(col));
		return;
	}
	for (int i = 0; i < m; i++) {
		if (v[i]) continue;
		if (!col.empty() && col[level - 1].y > i) continue;
		v[i] = 1;
		col.push_back({n, i, 0});
		dfs(level + 1, col);
		col.pop_back();
		v[i] = 0;
	}
}

int main() {
	input();
	vector<Pos> col;
	dfs(0, col);
	cout << ans;
}