#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 9999999999;
int n, m, x, y, z;
vector<vector<pair<long long, int>>> lst;

long long bfs(int start, int end, int flag) {
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        pair<long long, int> cur = pq.top(); pq.pop();
        long long cd = cur.first;
        int cn = cur.second;
        if (dist[cn] != cd) continue;

        for (pair<long long, int> next : lst[cn]) {
            long long nd = next.first;
            int nn = next.second;
            if (flag && nn == y) continue;
            if (dist[nn] > cd + nd) {
                dist[nn] = cd + nd;
                pq.push({ dist[nn], nn });
            }
        }
    }
    return dist[end];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    lst.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lst[a].push_back({ c, b });
    }
    
    cin >> x >> y >> z;
    long long first = bfs(x, y, 0) + bfs(y, z, 0);
    long long second = bfs(x, z, 1);
    
    if (first >= INF) cout << -1 << " ";
    else cout << first << " ";
    if (second >= INF) cout << -1;
    else cout << second;
}
