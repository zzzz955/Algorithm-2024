#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 999999999;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int paths[1001] = { 0 };
    cin >> n >> m;
    vector<vector<pair<int, int>>> lst(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lst[a].push_back({ c, b });
    }
    int sx, dx;
    cin >> sx >> dx;
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, sx });
    dist[sx] = 0;

    while (!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        int cd = cur.first, cn = cur.second;
        if (dist[cn] != cd) continue;

        for (pair<int, int> next : lst[cn]) {
            int nd = next.first, nn = next.second;
            if (dist[nn] > cd + nd) {
                dist[nn] = cd + nd;
                paths[nn] = cn;
                pq.push({ dist[nn], nn });
            }
        }
    }
    cout << dist[dx] << "\n";

    vector<int> ans = { dx };
    while (sx != dx) {
        int next = paths[dx];
        ans.push_back(next);
        dx = next;
    }

    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());

    for (int a : ans) {
        cout << a << " ";
    }
}
