#include <bits/stdc++.h>

using namespace std;

int dp[12345678];
int v[7];
int n;
unordered_set<int> dic;

void bt(int level, string str, const string& numbers) {
    if (level) dic.insert(stoi(str));
    if (level == n) return;
    
    for (int i = 0; i < n; i++) {
        if (v[i]) continue;
        v[i] = 1;
        bt(level + 1, str + numbers[i], numbers);
        v[i] = 0;
    }
}

int solution(string numbers) {
    n = numbers.size();
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i < 10000000; i++) {
        if (dp[i]) continue;
        for (int j = 2; j * i < 10000000; j++) {
            dp[j * i] = 1;
        }
    }
    bt(0, "", numbers);
    
    int answer = 0;
    
    for (int s:dic) {
        cout << s << "\n";
        if (!dp[s]) answer++;
    }
    
    return answer;
}