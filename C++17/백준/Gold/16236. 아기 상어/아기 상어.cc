#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, sx, sy;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

struct Pos {
	int x, y, dist, body, eat;
};

struct cmp {
	bool operator()(const Pos& left, const Pos& right) const {
		if (left.dist != right.dist) {
			return left.dist > right.dist;  // 거리(dist)가 작은 것이 우선
		}
		if (left.x != right.x) {
			return left.x > right.x;  // x가 작은 것이 우선
		}
		return left.y > right.y;  // y가 작은 것이 우선
	}
};

int bfs(Pos start, vector<vector<int>>& lst) {
    int total_time = 0;

    while (true) {
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<Pos> q;
        q.push(start);
        dist[start.x][start.y] = 0;

        vector<Pos> fishes;
        int min_dist = -1;

        while (!q.empty()) {
            Pos now = q.front();
            q.pop();
            int x = now.x, y = now.y, d = now.dist;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1 && lst[nx][ny] <= now.body) {
                    dist[nx][ny] = d + 1;
                    q.push({ nx, ny, d + 1, now.body, now.eat });

                    if (lst[nx][ny] > 0 && lst[nx][ny] < now.body) {
                        if (min_dist == -1 || d + 1 < min_dist) {
                            min_dist = d + 1;
                            fishes.clear();
                            fishes.push_back({ nx, ny, d + 1, now.body, now.eat });
                        }
                        else if (d + 1 == min_dist) {
                            fishes.push_back({ nx, ny, d + 1, now.body, now.eat });
                        }
                    }
                }
            }
        }

        if (fishes.empty()) {
            return total_time;
        }

        sort(fishes.begin(), fishes.end(), [](const Pos& a, const Pos& b) {
            if (a.x != b.x) return a.x < b.x;
            return a.y < b.y;
            });

        Pos chosen_fish = fishes[0];
        total_time += chosen_fish.dist;
        start = { chosen_fish.x, chosen_fish.y, 0, chosen_fish.body, chosen_fish.eat + 1 };

        if (start.eat == start.body) {
            start.body++;
            start.eat = 0;
        }

        lst[chosen_fish.x][chosen_fish.y] = 0;
    }
}

int main() {
	cin >> n;
	vector<vector<int>> lst(n, vector<int>(n));
	Pos pos;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> lst[i][j];
			if (lst[i][j] == 9) {
				pos = { i, j, 0, 2, 0 };
				lst[i][j] = 0;
			}
		}
	}
	cout << bfs(pos, lst);
}