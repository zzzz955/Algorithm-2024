#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, case1 = 0, case2 = 0;;
vector<string> lst1;
vector<string> lst2;

struct pos {
	int x, y;
};

void bfs1(pos xy, char c) {
	queue<pos> q;
	q.push(xy);

	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		int cx = now.x, cy = now.y;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && lst1[nx][ny] == c) {
				lst1[nx][ny] = '_';
				q.push({ nx, ny});
			}
		}
	}
}

void bfs2(pos xy, char c) {
	queue<pos> q;
	q.push(xy);
	int flag = 0;
	if (c == 'R' || c == 'G') {
		flag = 1;
	}

	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		int cx = now.x, cy = now.y;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (flag) {
					if (lst2[nx][ny] == 'R' || lst2[nx][ny] == 'G') {
						lst2[nx][ny] = '_';
						q.push({ nx, ny });
					}
				}
				else {
					if (lst2[nx][ny] == c) {
						lst2[nx][ny] = '_';
						q.push({ nx, ny });
					}
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		lst1.push_back(s);
	}
	lst2 = lst1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (lst1[i][j] != '_') {
				bfs1({ i, j }, lst1[i][j]);
				case1++;
			}
			if (lst2[i][j] != '_') {
				bfs2({ i, j }, lst2[i][j]);
				case2++;
			}
		}
	}
	cout << case1 << " " << case2;
}