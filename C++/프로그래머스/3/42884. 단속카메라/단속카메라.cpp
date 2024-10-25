#include <bits/stdc++.h>

using namespace std;

struct Wait {
    int it, ot;
    bool operator<(const Wait& other) const {
        return it > other.it;
    }
};

struct Ing {
    int it, ot;
    bool operator<(const Ing& other) const {
        return ot > other.ot;
    }
};

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int n = routes.size();
    
    priority_queue<Wait> pq1;
    priority_queue<Ing> pq2;
    for (vector<int> i : routes) pq1.push({i[0], i[1]});
    
    int cur = -30000;
    while (!pq1.empty() || !pq2.empty()) {
        while (!pq1.empty() && pq1.top().it <= cur) {
            Wait wait = pq1.top(); pq1.pop();
            pq2.push({wait.it, wait.ot});
        }
        
        
        
        if (!pq2.empty()) {
            cur = pq2.top().ot;
            answer++;
        }
        
        while (!pq2.empty() && pq2.top().it <= cur) pq2.pop();
        if (!pq1.empty()) cur = pq1.top().ot;
        cout << cur << " ";
    }
    
    return answer;
}