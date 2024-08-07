#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int min_val = 999999999;
vector<vector<int>> f;

struct POS {
    int x, time;
};

int bfs(int now) {
    queue<POS> q;
    q.push({ now, 0 });
    int v[101] = { 0 };
    v[now] = 1;
    int cnt = 0;

    while (!q.empty()) {
        if (cnt > min_val) return cnt;
        POS pos = q.front(); q.pop();
        int cx = pos.x, ct = pos.time;
        for (int i : f[cx]) {
            if (v[i]) continue;
            v[i] = 1;
            cnt += ct + 1;
            q.push({ i, ct + 1 });
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    f.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        f[n1].push_back(n2);
        f[n2].push_back(n1);
    }

    vector<int> kb(n + 1);

    for (int i = 1; i <= n; i++) {
        kb[i] = bfs(i);
        if (min_val > kb[i]) {
            min_val = kb[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (kb[i] == min_val) {
            cout << i;
            break;
        }        
    }
}