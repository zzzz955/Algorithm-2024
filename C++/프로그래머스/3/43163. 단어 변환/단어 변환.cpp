#include <bits/stdc++.h>

using namespace std;

int n, len, ans = 1e9;
int v[50];

void bt(int level, string begin, const string& target, const vector<string> words) {
    if (ans <= level) return;
    if (begin == target) {
        ans = min(ans, level);
        return;
    }
    
    for (int i = 0; i < len; i++) {
        if (v[i]) continue;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (begin[j] != words[i][j]) cnt++;
        }
        if (cnt > 1) continue;
        v[i] = 1;
        bt(level + 1, words[i], target, words);
        v[i] = 0;
    }
}

int solution(string begin, string target, vector<string> words) {
    n = begin.size();
    len = words.size();
    if (find(words.begin(), words.end(), target) == words.end()) return 0;
    bt(0, begin, target, words);
    
    return ans;
}