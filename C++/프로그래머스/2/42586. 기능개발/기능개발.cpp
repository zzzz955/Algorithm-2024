#include <bits/stdc++.h>

using namespace std;

int v[200];

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    queue<int> s;
    for (int i : progresses) q.push(i);
    for (int i : speeds) s.push(i);
    
    int day = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        int w = s.front(); s.pop();
        
        if (cur + w * day < 100) day = ceil((100 - cur) / (double)w);
        v[day]++;
    }
    
    for (int t:v) {
        if(t) answer.push_back(t);        
    }
    
    return answer;
}