#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int n = people.size();
    deque<int> deq;
    for (int i = 0; i < n; i++) deq.push_back(people[i]);
    sort(deq.begin(), deq.end());
    
    while (!deq.empty()) {
        if (deq.size() > 1 && deq.back() + deq.front() <= limit) {
            deq.pop_back();
            deq.pop_front();
        }
        else deq.pop_back();
        answer++;
    }
    
    return answer;
}