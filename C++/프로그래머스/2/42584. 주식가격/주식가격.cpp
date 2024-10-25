#include <bits/stdc++.h>

using namespace std;
int v[100000];

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int n = prices.size();
    
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top().first > prices[i]) {
            pair<int, int> cur = pq.top(); pq.pop();
            v[cur.second] = i - cur.second;
        }
        pq.push({prices[i], i});
    }
    
    while (!pq.empty()) {
            pair<int, int> cur = pq.top(); pq.pop();
            v[cur.second] = n - 1 - cur.second;
        }
    
    for (int i = 0; i < n; i++) answer.push_back(v[i]);
    
    return answer;
}