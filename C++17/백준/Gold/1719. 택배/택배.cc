#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> lst;

void init() {
    lst.resize(n + 1);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        lst[a].push_back({ c, b });
        lst[b].push_back({ c, a });
    }
}

void bfs(int start) {
    vector<int> dist(n + 1, 999999999);
    vector<int> path(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        pair<int, int>  cur = pq.top(); pq.pop();
        int cd = cur.first, cn = cur.second;
        if (dist[cn] != cd) continue;
        for (pair<int, int> next : lst[cn]) {
            int nd = next.first, nn = next.second;
            if (dist[nn] > cd + nd) {
                dist[nn] = cd + nd;
                if (!path[cn]) path[nn] = nn;
                else path[nn] = path[cn];
                pq.push({ dist[nn], nn });
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i == start) cout << "-" << " ";
        else cout << path[i] << " ";
    }
    cout << "\n";
}

void solution() {
    for (int i = 1; i <= n; i++) {
        bfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    init();
    solution();
}
