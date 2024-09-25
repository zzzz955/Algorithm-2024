#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int n, ans = 0;
vector<vector<int>> map;

int simulation(vector<vector<int>>& lst, vector<vector<int>>& temp, int dir, int val) {
    if (dir == 0) { // 오른쪽으로 이동
        for (int i = 0; i < n; i++) {
            int q[20], qidx = 0, qcnt = 0;
            for (int j = n - 1; j >= 0; j--) if (lst[i][j]) q[qcnt++] = lst[i][j];

            int index = n - 1;
            while (qidx < qcnt) {
                int value = q[qidx];
                if (qidx + 1 < qcnt && value == q[qidx + 1]) { // 합치기
                    temp[i][index--] = value * 2;
                    val = max(val, value * 2);
                    qidx++;
                }
                else temp[i][index--] = value;
                qidx++;
            }
        }
    }
    else if (dir == 1) { // 왼쪽으로 이동
        for (int i = 0; i < n; i++) {
            int q[20], qidx = 0, qcnt = 0;
            for (int j = 0; j < n; j++) if (lst[i][j]) q[qcnt++] = lst[i][j];

            int index = 0;
            while (qidx < qcnt) {
                int value = q[qidx];
                if (qidx + 1 < qcnt && value == q[qidx + 1]) { // 합치기
                    temp[i][index++] = value * 2;
                    val = max(val, value * 2);
                    qidx++;
                }
                else temp[i][index++] = value;
                qidx++;
            }
        }
    }
    else if (dir == 2) { // 아래로 이동
        for (int j = 0; j < n; j++) {
            int q[20], qidx = 0, qcnt = 0;
            for (int i = n - 1; i >= 0; i--) if (lst[i][j]) q[qcnt++] = lst[i][j];

            int index = n - 1;
            while (qidx < qcnt) {
                int value = q[qidx];
                if (qidx + 1 < qcnt && value == q[qidx + 1]) { // 합치기
                    temp[index--][j] = value * 2;
                    val = max(val, value * 2);
                    qidx++;
                }
                else temp[index--][j] = value;
                qidx++;
            }
        }
    }
    else if (dir == 3) { // 위로 이동
        for (int j = 0; j < n; j++) {
            int q[20], qidx = 0, qcnt = 0;
            for (int i = 0; i < n; i++) if (lst[i][j]) q[qcnt++] = lst[i][j];

            int index = 0;
            while (qidx < qcnt) {
                int value = q[qidx];
                if (qidx + 1 < qcnt && value == q[qidx + 1]) { // 합치기
                    temp[index++][j] = value * 2;
                    val = max(val, value * 2);
                    qidx++;
                }
                else temp[index++][j] = value;
                qidx++;
            }
        }
    }
    return val;
}


void dfs(int level, vector<vector<int>>& map, int val) {
    if (level == 10) {
        ans = max(ans, val);
        return;
    }
    if (val * pow(2, 10 - level) <= ans) return;
    for (int i = 0; i < 4; i++) {
        vector<vector<int>> temp(n, vector<int>(n, 0));
        int new_val = simulation(map, temp, i, val);
        int flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] != temp[i][j]) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag) dfs(level + 1, temp, new_val);
    }
}

int main() {
    cin >> n;
    map.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            ans = max(ans, map[i][j]);
        }
    }

    dfs(0, map, ans);
    cout << ans;
}