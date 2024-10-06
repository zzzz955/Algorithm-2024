#include<iostream>
#include<queue>

using namespace std;
int tc, n, k, sx, sy, ex, ey, ans;
string lst[10];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

struct Pos {
    int x, y, dir, cut, time;
    bool operator<(const Pos& other) const {
        return time > other.time;
    }
};

void input() {
    ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
        for (int j = 0; j < n; j++) {
            if (lst[i][j] == 'X') sx = i, sy = j;
            else if (lst[i][j] == 'Y') ex = i, ey = j;
        }
    }
}

void print(int x, int y, int dir, int cuts, int time) {
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == x && j == y) cout << "@";
            else if (lst[i][j] == 'G' || lst[i][j] == 'X' || lst[i][j] == 'Y') cout << "%";
            else if (lst[i][j] == 'T') cout << "#";
        }
        cout << "\n";
    }
    cout << dir << " " << cuts << " " << time << "\n";
}

int solution() {
    priority_queue<Pos> pq;
    pq.push({ sx, sy, 0, 0, 0 });
    vector<vector<vector<int>>> dist(k + 1, vector<vector<int>>(n, vector<int>(n, 1e9)));
    dist[0][sx][sy] = 0;

    while (!pq.empty()) {
        Pos pos = pq.top(); pq.pop();
        int cx = pos.x, cy = pos.y, cd = pos.dir, cc = pos.cut, ct = pos.time;
        if (dist[cc][cx][cy] != ct) continue;
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i], nc = cc, nt = ct + 1;
            if (abs(cd - i) == 3) nt += 1;
            else nt += abs(cd - i);
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (lst[nx][ny] == 'T') {
                    if (nc >= k) continue;
                    else nc++;
                }
                if (dist[nc][nx][ny] > nt) {
                    dist[nc][nx][ny] = nt;
                    //print(nx, ny, i, nc, nt);
                    pq.push({ nx, ny, i, nc, nt });
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= k; i++) ans = min(ans, dist[i][ex][ey]);
    if (ans == 1e9) return -1;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        input();
        cout << "#" << t << " " << solution() << "\n";
    }
}