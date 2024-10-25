#include <bits/stdc++.h>

using namespace std;
unordered_map<int, int> dic;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int, vector<int>, greater<int>> min_pq;
    priority_queue<int> max_pq;
    for(const string& s : operations) {
        stringstream ss(s);
        string op, val;
        getline(ss, op, ' ');
        getline(ss, val, ' ');
        
        int n = stoi(val);
        if (op == "I") {
            min_pq.push(n);
            max_pq.push(n);
            dic[n]++;
        } else {
            if (val == "1") {
                while (!max_pq.empty()) {
                    if (!dic[max_pq.top()]) {
                        max_pq.pop();
                        continue;
                    } else {
                        dic[max_pq.top()]--;
                        max_pq.pop();
                        break;
                    }
                }
            }
            else {
                while (!min_pq.empty()) {
                    if (!dic[min_pq.top()]) {
                        min_pq.pop();
                        continue;
                    } else {
                        dic[min_pq.top()]--;
                        min_pq.pop();
                        break;
                    }
                }
            }
        }
    }
    
    while (!max_pq.empty() && !dic[max_pq.top()]) max_pq.pop();
    while (!min_pq.empty() && !dic[min_pq.top()]) min_pq.pop();
    
    if (!max_pq.empty()) answer.push_back(max_pq.top());
    else answer.push_back(0);
    
    if (!min_pq.empty()) answer.push_back(min_pq.top());
    else answer.push_back(0);
    
    return answer;
}