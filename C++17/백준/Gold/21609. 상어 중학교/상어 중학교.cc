#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int n, m, ans;
int lst[20][20];
int v[20][20];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

struct Pos {
	int x, y;
};

vector<Pos> common;
vector<Pos> rainbow;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> lst[i][j];
}

void bfs(int sx, int sy) {
	queue<Pos> q;
	vector<Pos> common_path(1, { sx, sy });
	vector<Pos> rainbow_path;
	q.push({ sx, sy });
	v[sx][sy] = lst[sx][sy];
	int cur = lst[sx][sy];
	int cnt = 1;
	int rain_cnt = 0;

	while (!q.empty()) {
		Pos Pos = q.front(); q.pop();
		int cx = Pos.x, cy = Pos.y;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			int next = lst[nx][ny];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && next >= 0) {
				if (cur != next && next != 0) continue;
				if (v[nx][ny] == cur) continue;
				v[nx][ny] = cur;
				if (!next) {
					rain_cnt++;
					rainbow_path.push_back({ nx, ny });
				}
				else common_path.push_back({ nx, ny });
				cnt++;
				q.push({ nx, ny });
			}
		}
	}

	int csize = common.size();
	int rsize = rainbow.size();
	int flag = 0;

	if (cnt > csize + rsize) flag = 1;
	else if (cnt == csize + rsize) {
		if (rain_cnt > rsize) flag = 1;
		else if (rain_cnt == rsize) {
			if (common_path[0].x > common[0].x) flag = 1;
			else if (common_path[0].x == common[0].x) {
				if (common_path[0].y > common[0].y) flag = 1;
			}
		}
	}

	if (flag) {
		common = common_path;
		rainbow = rainbow_path;
	}
}

void grav() {
	for (int j = 0; j < n; ++j) {
		int h = 0;
		vector<int> stack;
		while (h < n) {
			if (lst[h][j] == -1 && !stack.empty()) {
				int nh = h;
				while (!stack.empty()) {
					lst[--nh][j] = stack.back();
					stack.pop_back();
				}
			}

			if (lst[h][j] >= 0) {
				stack.push_back(lst[h][j]);
				lst[h][j] = -2;
			}

			h++;
		}

		while (!stack.empty()) {
			lst[--h][j] = stack.back();
			stack.pop_back();
		}
	}
}

void spin() {
	int temp[20][20];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			temp[n - j - 1][i] = lst[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			lst[i][j] = temp[i][j];
		}
	}
}

void vprint() {
	cout << "V\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

void mprint() {
	cout << "LST, ans : " << ans << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (lst[i][j] >= 0) cout << lst[i][j] << "  ";
			else if (lst[i][j] == -1) cout << lst[i][j] << " ";
			else cout << "   ";
		}
		cout << "\n";
	}
}

void autoplay() {
	while (1) {
		bool flag = 0;
		memset(v, 0, sizeof(v));
		common.clear();
		rainbow.clear();

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (lst[i][j] <= 0 || v[i][j]) continue;
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k], ny = j + dy[k];
					if (0 <= nx && nx < n && 0 <= ny && ny < n && (lst[nx][ny] == lst[i][j] || lst[nx][ny] == 0) && v[nx][ny] != lst[i][j]) {
						flag = 1;
						bfs(i, j);
					}
				}
			}
		}
		
		if (!flag) break;

		for (Pos pos : rainbow) lst[pos.x][pos.y] = -2;
		for (Pos pos : common) lst[pos.x][pos.y] = -2;
		ans += pow(rainbow.size() + common.size(), 2);

		//vprint();
		//mprint();
		grav();
		//mprint();
		spin();
		//mprint();
		grav();
		//mprint();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	autoplay();
	cout << ans;
}