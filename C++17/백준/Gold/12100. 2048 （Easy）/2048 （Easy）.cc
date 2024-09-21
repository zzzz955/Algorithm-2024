#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, ans = 0;
vector<vector<int>> map;
vector<int> path;

void simulation(vector<vector<int>>& lst, int dir) {
    if (dir == 0) { // 오른쪽으로 이동
        for (int i = 0; i < n; i++) {
            queue<int> q;
            for (int j = n - 1; j >= 0; j--) if (lst[i][j]) q.push(lst[i][j]);

            // 초기화
            fill(lst[i].begin(), lst[i].end(), 0);

            int index = n - 1;
            while (!q.empty()) {
                int value = q.front(); q.pop();
                if (!q.empty() && value == q.front()) { // 합치기
                    lst[i][index--] = value * 2;
                    q.pop(); // 두 개의 블록을 하나로 합친 후 pop
                }
                else {
                    lst[i][index--] = value;
                }
            }
        }
    }
    else if (dir == 1) { // 왼쪽으로 이동
        for (int i = 0; i < n; i++) {
            queue<int> q;
            for (int j = 0; j < n; j++) if (lst[i][j]) q.push(lst[i][j]);

            fill(lst[i].begin(), lst[i].end(), 0);

            int index = 0;
            while (!q.empty()) {
                int value = q.front(); q.pop();
                if (!q.empty() && value == q.front()) {
                    lst[i][index++] = value * 2;
                    q.pop();
                }
                else {
                    lst[i][index++] = value;
                }
            }
        }
    }
    else if (dir == 2) { // 아래로 이동
        for (int j = 0; j < n; j++) {
            queue<int> q;
            for (int i = n - 1; i >= 0; i--) if (lst[i][j]) q.push(lst[i][j]);

            for (int i = n - 1; i >= 0; i--) lst[i][j] = 0;

            int index = n - 1;
            while (!q.empty()) {
                int value = q.front(); q.pop();
                if (!q.empty() && value == q.front()) {
                    lst[index--][j] = value * 2;
                    q.pop();
                }
                else {
                    lst[index--][j] = value;
                }
            }
        }
    }
    else if (dir == 3) { // 위로 이동
        for (int j = 0; j < n; j++) {
            queue<int> q;
            for (int i = 0; i < n; i++) if (lst[i][j]) q.push(lst[i][j]);

            for (int i = 0; i < n; i++) lst[i][j] = 0;

            int index = 0;
            while (!q.empty()) {
                int value = q.front(); q.pop();
                if (!q.empty() && value == q.front()) {
                    lst[index++][j] = value * 2;
                    q.pop();
                }
                else {
                    lst[index++][j] = value;
                }
            }
        }
    }
}


void dfs(int level, vector<vector<int>>& map) {
    if (level == 5) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, map[i][j]);
            }
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        vector<vector<int>> lst = map;
        simulation(lst, i);
        dfs(level + 1, lst);
    }
}

int main() {
    cin >> n;
    map.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0, map);
    cout << ans;
}