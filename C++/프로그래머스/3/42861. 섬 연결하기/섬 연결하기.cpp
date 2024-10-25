#include <bits/stdc++.h>

using namespace std;

int nodes[100];
struct Bridge {
    int cur, next, w;
    bool operator<(const Bridge& other) const {
        return w < other.w;
    }
};

int Find(int a) {
    if (nodes[a] == a) return a;
    return nodes[a] = Find(nodes[a]);
}

bool Union(int a, int b) {
    int A = Find(a);
    int B = Find(b);
    if (A == B) return false;
    nodes[B] = A;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i = 0; i < n; i++) nodes[i] = i;
    
    vector<Bridge> lst;
    for (int i = 0; i < costs.size(); i++) {
        lst.push_back({costs[i][0], costs[i][1], costs[i][2]});
    }
    sort(lst.begin(), lst.end());
    
    for (int i = 0; i < lst.size(); i++) {
        Bridge bridge = lst[i];
        if (Union(bridge.cur, bridge.next)) answer += bridge.w;
    }
    
    return answer;
}