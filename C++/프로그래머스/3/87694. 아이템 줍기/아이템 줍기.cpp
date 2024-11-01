#include <bits/stdc++.h>

using namespace std;
int v[101][101];
int lst[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Pos {
    int x, y, t;
};

int bfs(int sx, int sy, int ex, int ey) {
    queue<Pos> q;
    q.push({sx, sy, 0});
    v[sx][sy] = 1;
    
    while (!q.empty()) {
        Pos pos = q.front(); q.pop();
        int cx = pos.x, cy = pos.y, ct = pos.t;
        if (cx == ex && cy == ey) return ct / 2;
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1;
            if (0 <= nx && nx < 101 && 0 <= ny && ny < 101 && !v[nx][ny] && !lst[nx][ny]) {
                v[nx][ny] = 1;
                q.push({nx, ny, nt});
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    memset(lst, -1, sizeof(lst));
    for (auto& r : rectangle) {
        int x1 = r[0] * 2, x2 = r[2] * 2;
        int y1 = r[1] * 2, y2 = r[3] * 2;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (x1 < i && i < x2 && y1 < j && j < y2) lst[i][j] = 1;
                else if (lst[i][j] == -1) lst[i][j] = 0;
            }
        }
    }
    
    return bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
}