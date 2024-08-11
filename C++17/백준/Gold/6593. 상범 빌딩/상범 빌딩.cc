#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int l, r, c;
int sx, sy, sz, dx, dy, dz;
int dirx[] = { 1, 0, 0, 0, 0, -1 };
int diry[] = { 0, 1, -1, 0, 0, 0 };
int dirz[] = { 0, 0, 0, 1, -1, 0 };


struct Pos {
    int x, y, z, time;
};

int bfs(vector<vector<string>>& lst) {
    queue<Pos> q;
    q.push({ sx, sy, sz, 0 });
    int v[31][31][31] = { 0 };

    while (!q.empty()) {
        Pos pos = q.front(); q.pop();
        int x = pos.x, y = pos.y, z = pos.z, t = pos.time;
        if (x == dx && y == dy && z == dz) return t;

        for (int i = 0; i < 6; i++) {
            int nx = x + dirx[i], ny = y + diry[i], nz = z + dirz[i], nt = t + 1;
            if (0 <= nx && nx < l && 0 <= ny && ny < r && 0 <= nz && nz < c && !v[nx][ny][nz] && lst[nx][ny][nz] == '.') {
                v[nx][ny][nz] = 1;
                q.push({ nx, ny, nz, nt });
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        cin >> l >> r >> c;
        if (!l && !r && !c) break;
        vector<vector<string>> lst(l, vector<string>(r));
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                cin >> lst[i][j];
                for (int k = 0; k < c; k++) {
                    if (lst[i][j][k] == 'S') {
                        sx = i, sy = j, sz = k;
                        lst[i][j][k] = '.';
                    }
                    if (lst[i][j][k] == 'E') {
                        dx = i, dy = j, dz = k;
                        lst[i][j][k] = '.';
                    }
                }
            }
        }
        int ans = bfs(lst);
        if (ans != -1) cout << "Escaped in " << ans << " minute(s).\n";
        else cout << "Trapped!\n";
    }
}