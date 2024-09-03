#include<iostream>

using namespace std;

int tc, n, x, ans = 0;
int lst[100][100];
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };

void input() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> lst[i][j];
        }
    }
}

void col_bfs(int sx, int sy) {
    int ny = sy + 1, u = 0, d = 0, g = 0, flag = 0, ch = lst[sx][sy];
    while (0 <= ny && ny < n) {
        if (abs(lst[sx][ny] - ch) > 1) return;
        if (lst[sx][ny] > ch) {
            if (u > 0) return;
            if (ny - x < 0) return;
            if (flag == -1 && g > 0) return;
            ch++;
            u = x;
            flag = 1;
        }
        else if (lst[sx][ny] < ch) {
            if (ny + x > n) return;
            if (d > 0) return;
            ch--;
            flag = -1;
            d = x;
            g = 2 * x;
        }
        u--;
        d--;
        g--;
        ny++;
    }
    ans++;
}

void row_bfs(int sx, int sy) {
    int nx = sx + 1, u = 0, d = 0, g = 0, flag = 0, ch = lst[sx][sy];
    while (0 <= nx && nx < n) {
        if (abs(lst[nx][sy] - ch) > 1) return;
        if (lst[nx][sy] > ch) {
            if (u > 0) return;
            if (nx - x < 0) return;
            if (flag == -1 && g > 0) return;
            ch++;
            u = x;
            flag = 1;
        }
        else if (lst[nx][sy] < ch) {
            if (nx + x > n) return;
            if (d > 0) return;
            ch--;
            flag = -1;
            d = x;
            g = 2 * x;
        }
        u--;
        d--;
        g--;
        nx++;
    }
    ans++;
}

void solution() {
    for (int i = 0; i < n; i++) {
        col_bfs(i, 0);
        row_bfs(0, i);
    }
}

int main() {
    input();
    solution();
    cout << ans;
}