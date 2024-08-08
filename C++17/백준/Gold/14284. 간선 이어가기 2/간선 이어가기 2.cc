#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 999999999;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> lst(n + 1);
    vector<int> dist(n + 1, INF);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lst[a].push_back({ c, b });
        lst[b].push_back({ c, a });
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    int sn, dn;
    cin >> sn >> dn;

    pq.push({ 0, sn });
    dist[sn] = 0;

    while (!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        int cd = cur.first, cn = cur.second;
        if (dist[cn] != cd) continue;

        for (pair<int, int> next : lst[cn]) {
            int nd = next.first, nn = next.second;
            if (dist[nn] > cd + nd) {
                dist[nn] = cd + nd;
                //if (nn == dn) break;
                pq.push({ dist[nn], nn });
            }
        }
    }
    cout << dist[dn];
}
