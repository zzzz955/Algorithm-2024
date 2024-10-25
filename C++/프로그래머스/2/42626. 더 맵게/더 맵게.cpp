#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i : scoville) pq.push(i);
    
    while (pq.size() > 1 && pq.top() < K) {
        int food1 = pq.top(); pq.pop();
        int food2 = pq.top(); pq.pop();
        int new_food = food1 + food2 * 2;
        answer++;
        pq.push(new_food);
    }
    
    if (!pq.empty() && pq.top() < K) answer = -1;
    
    return answer;
}