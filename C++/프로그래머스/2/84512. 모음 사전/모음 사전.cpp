#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> dic;
string s = "AEIOU";
int idx;

void bt(int level, string str) {
    if (level && !dic[str]) dic[str] = ++idx;
    if (level == 5) return;
    
    for (int i = 0; i < 5; i++) {
        bt(level + 1, str + s[i]);
    }
}

int solution(string word) {
    int answer = 0;
    
    bt(0, "");
    answer = dic[word];
    
    return answer;
}