#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;

struct Pos {
    int n, idx;
};

queue<Pos> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    for (int i = 0; i < priorities.size(); i++) {
        int n = priorities[i];
        pq.push(n);
        q.push({n, i});
    }
    
    int cnt = 0;
    while(!pq.empty()) {
        int cur = pq.top(); pq.pop();
        while (1) {
            Pos pos = q.front(); q.pop();
            if (pos.n == cur) {
                cnt++;
                if (pos.idx == location) return cnt;
                break;
            }
            else q.push(pos);
        }
    }
    
    return answer;
}