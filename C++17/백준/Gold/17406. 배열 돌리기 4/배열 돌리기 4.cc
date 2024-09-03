#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int n, m, k, ans = 1e9;
int lst[51][51];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int v[6] = { 0, };

struct Pos {
    int tx, ty, bx, by, s;
};

struct Sim {
    int x, y, d;
};

Pos pos[6];

void input() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> lst[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        int a, b, c; cin >> a >> b >> c;
        pos[i] = { a - c, b - c, a + c, b + c, c };
    }
}

void bfs(int sx, int sy, int ex, int ey, int dir, int turn) {
    queue<Sim> q;
    q.push({ sx, sy, dir });

    while (!q.empty()) {
        Sim sim = q.front(); q.pop();
        int cx = sim.x, cy = sim.y, cd = sim.d;
        int nx = cx + dx[cd], ny = cy + dy[cd];
        if (sx <= nx && nx <= ex && sy <= ny && ny <= ey) {
            if (nx == sx && ny == sy) return;
            swap(lst[sim.x][sim.y], lst[nx][ny]);
            q.push({ nx, ny, cd });
        }
        else {
            q.push({ sim.x, sim.y, (cd + turn) % 4 });
        }
    }
}

void spin_sqr(int tx, int ty, int bx, int by, int s, int dir, int turn) {
    for (int i = 0; i < s; i++) {
        bfs(tx + i, ty + i, bx - i, by - i, dir, turn);
    }
}

void simul(vector<int>& path, int flag) {
    if (flag) {
        for (int i = 0; i < k; i++) {
            Pos now = pos[path[i]];
            spin_sqr(now.tx, now.ty, now.bx, now.by, now.s, 1, 3);
        }
    }
    else {
        for (int i = k - 1; i >= 0; i--) {
            Pos now = pos[path[i]];
            spin_sqr(now.tx, now.ty, now.bx, now.by, now.s, 0, 1);
        }
    }
}

int chk() {
    int min_val = 1e9;
    for (int i = 1; i <= n; i++) {
        int row_val = 0;
        for (int j = 1; j <= m; j++) {
            row_val += lst[i][j];
        }
        min_val = min(min_val, row_val);
    }
    return min_val;
}

void dfs(int level, vector<int>& path) {
    if (level == k) {
        simul(path, 1);
        ans = min(ans, chk());
        simul(path, 0);
        return;
    }

    for (int i = 0; i < k; i++) {
        if (v[i]) continue;
        v[i] = 1;
        path.push_back(i);
        dfs(level + 1, path);
        path.pop_back();
        v[i] = 0;
    }
}

int main() {
    input();
    vector<int> path;
    dfs(0, path);
    cout << ans;
}