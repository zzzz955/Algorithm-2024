#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int n, m, ans = 2e9;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<vector<int>>lst;

struct BBQ {
	int x, y, d;
};

vector<BBQ> bbqs;
vector<int> choose;
int cnt;
int chic[14];
int v[50][50];

int Find(vector<vector<int>>& map) {
	queue<BBQ> q;
	for (int i = 0; i < m; i++) q.push(bbqs[choose[i]]);
	memset(v, 0, sizeof(v));
	int dist = 0;

	while (!q.empty()) {
		BBQ cur = q.front(); q.pop();
		int cx = cur.x, cy = cur.y, cd = cur.d;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i], nd = cd + 1;
			if (0 <= nx && nx < n && 0 <= ny && ny < n && !v[nx][ny]) {
				v[nx][ny] = 1;
				if (map[nx][ny] == 1) {
					map[nx][ny] = 0;
					dist += nd;
				}
				q.push({ nx, ny, nd });
			}
		}
	}
	return dist;
}

void bt(int level) {
	if (level >= m) {
		vector<vector<int>> new_map = lst;
		ans = min(ans, Find(new_map));
		return;
	}

	for (int i = 0; i < cnt; i++) {
		if (chic[i]) continue;
		if (!choose.empty() && i < choose.back()) continue;
		chic[i] = 1;
		choose.push_back(i);
		bt(level + 1);
		chic[i] = 0;
		choose.pop_back();
	}
}

int main() {
	cin >> n >> m;
	lst.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> lst[i][j];
			if (lst[i][j] == 2) bbqs.push_back({ i, j, 0 });
		}
	}

	cnt = bbqs.size();
	bt(0);
	cout << ans;
}