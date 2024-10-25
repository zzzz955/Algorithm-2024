#include <bits/stdc++.h>

using namespace std;

int v[101];

int bfs(int node, const vector<vector<int>>& lst) {
    queue<int> q;
    q.push(node);
    v[node] = 1;
    int cnt = 1;
    
    while (!q.empty()) {
        int cn = q.front(); q.pop();
        for (int nn : lst[cn]) {
            if (v[nn]) continue;
            v[nn] = 1;
            cnt++;
            q.push(nn);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    
    for (int i = 0; i < n - 1; i++) {
        vector<vector<int>> lst(n + 1);
        memset(v, 0, sizeof(v));
        for (int j = 0; j < n - 1; j++) {
            if (i == j) continue;
            lst[wires[j][0]].push_back(wires[j][1]);
            lst[wires[j][1]].push_back(wires[j][0]);
        }
        
        vector<int> result;
        for (int j = 1; j <= n; j++) {
            if (v[j]) continue;
            result.push_back(bfs(j, lst));
        }
        cout << "\n";
        answer = min(answer, abs(result[0] - result[1]));
    }
    
    return answer;
}