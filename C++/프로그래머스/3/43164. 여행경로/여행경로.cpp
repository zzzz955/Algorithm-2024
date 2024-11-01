#include <bits/stdc++.h>

using namespace std;

unordered_map<string, priority_queue<string, vector<string>, greater<string>>> dic;
vector<string> answer;

void dfs(string s) {
    while (!dic[s].empty()) {
        string nxt = dic[s].top();
        dic[s].pop();
        dfs(nxt);
    }
    answer.push_back(s);
}

vector<string> solution(vector<vector<string>> tickets) {
    for(const auto& ticket : tickets) dic[ticket[0]].push(ticket[1]);
    
    dfs("ICN");
    
    reverse(answer.begin(), answer.end());
    return answer;
}