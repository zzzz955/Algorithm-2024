#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, m;
int lst[10][10];
int nodes[8];

struct Pos {
    int d, x, y, index;
};

queue<Pos> island;

vector<tuple<int, int, int>> edges;

int Find(int a) {
    if (nodes[a] == a) return a;
    return nodes[a] = Find(nodes[a]);
}

void Union(int a, int b) {
    int rootA = Find(a);
    int rootB = Find(b);
    if (rootA == rootB) return;
    nodes[rootB] = rootA;
}

void chk_inner(int sx, int sy, int index) {
    queue<pair<int, int>> q;
    int v[10][10] = { 0, };
    q.push({ sx, sy });
    lst[sx][sy] = index;
    v[sx][sy] = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        int cx = cur.first, cy = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny] && lst[nx][ny] == 1) {
                v[nx][ny] = 1;
                lst[nx][ny] = index;
                q.push({ nx, ny });
            }
        }
    }
}

void bfs(int sx, int sy, int index) {
    queue<Pos> q;
    q.push({ 0, sx, sy });
    int v[10][10] = { 0, };
    v[sx][sy] = 1;

    while (!q.empty()) {
        Pos pos = q.front(); q.pop();
        int cx = pos.x, cy = pos.y, cd = pos.d;
        for (int i = 0; i < 4; i++) {
            int nx = cx, ny = cy, nd = cd;
            while (1) {
                nx += dx[i];
                ny += dy[i];
                nd++;
                if (0 > nx || nx >= n || 0 > ny || ny >= m) break;
                if (v[nx][ny]) break;
                if (lst[nx][ny] == index) {
                    v[nx][ny] = 1;
                    q.push({ 0, nx, ny });
                    break;
                }
                else if (2 <= lst[nx][ny]) {
                    v[nx][ny] = 1;
                    if (nd > 2) edges.push_back({ nd - 1, index, lst[nx][ny] });
                    break;
                }
                else v[nx][ny] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int node = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lst[i][j];
        }
    }

    int index = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lst[i][j] == 1) {
                chk_inner(i, j, index);
                island.push({ 0, i, j, index });
                index++;
                node++;
            }
        }
    }

    while (!island.empty()) {
        Pos now = island.front(); island.pop();
        bfs(now.x, now.y, now.index);
    }

    sort(edges.begin(), edges.end());

    for (int i = 2; i < 2 + node; i++) {
        nodes[i] = i;
    }

    int sum = 0, cnt = 0;
    for (int i = 0; i < edges.size(); i++) {
        tuple<int, int, int> edge = edges[i];
        int dist = get<0>(edge), cur_n = get<1>(edge), next_n = get<2>(edge);
        if (Find(cur_n) == Find(next_n)) continue;
        Union(cur_n, next_n);
        sum += dist;
        cnt++;
    }
    if (cnt == node - 1) cout << sum;
    else cout << -1;
}
