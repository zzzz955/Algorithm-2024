#include <bits/stdc++.h>

using namespace std;

int ans;
int nodes;
vector<int> lst[20001];

struct Pos {
    int cn, cd;
    bool operator<(const Pos& other) const {
        return cd > other.cd;
    }
};

int dijkstra() {
    priority_queue<Pos> pq;
    pq.push({1, 0});
    vector<int> dist(nodes + 1, 1e9);
    dist[1] = 0;
    
    while (!pq.empty()) {
        Pos pos = pq.top(); pq.pop();
        int cn = pos.cn, cd = pos.cd;
        
        for (int nn : lst[cn]) {
            if (dist[nn] > cd + 1) {
                dist[nn] = cd + 1;
                pq.push({nn, cd + 1});
            }
        }
    }
    int max_val = 0;
    for (int i = 1; i < nodes + 1; i++) {
        if (dist[i] != 1e9) max_val = max(max_val, dist[i]);
    }

    return count(dist.begin() + 1, dist.end(), max_val);;
}

int solution(int n, vector<vector<int>> edge) {
    nodes = n;
    for (const auto& e : edge) {
        lst[e[0]].push_back(e[1]);
        lst[e[1]].push_back(e[0]);
    }
    return dijkstra();
}