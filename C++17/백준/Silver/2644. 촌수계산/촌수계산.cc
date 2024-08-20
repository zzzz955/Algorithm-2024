#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int n, sn, dn, m;
int v[101] = { 0, };
vector<vector<int>> lst;

int bfs() {
    queue<int> q;
    q.push({ sn });

    while (!q.empty()) {
        int cn = q.front(); q.pop();
        if (cn == dn) return v[cn];
        for (int nn : lst[cn]) {
            if (!v[nn]) {
                v[nn] = v[cn] + 1;
                q.push(nn);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> sn >> dn >> m;
    lst.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        lst[a].push_back(b);
        lst[b].push_back(a);
    }
    cout << bfs();
}
