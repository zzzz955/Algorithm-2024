#include <bits/stdc++.h>

using namespace std;

int n, ans;
int v[8];

void bt(int level, int k, const vector<vector<int>>& dungeons) {
    for (int i = 0; i < n; i++) {
        if (v[i]) continue;
        if (dungeons[i][0] > k) continue;
        v[i] = 1;
        bt(level + 1, k - dungeons[i][1], dungeons);
        v[i] = 0;
    }
    ans = max(ans, level);
}

int solution(int k, vector<vector<int>> dungeons) {    
    n = dungeons.size();
    bt(0, k, dungeons);
    
    return ans;
}