#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int lst[31];
unordered_map<string, int> dic;

int solution(vector<vector<string>> clothes) {
    int idx = 1;
    for (auto cloth : clothes) {
        if (!dic[cloth[1]]) {
            lst[idx]++;
            dic[cloth[1]] = idx++;            
        }
        else lst[dic[cloth[1]]]++;
    }
    
    int cur = 1;
    for (int i = 1; i < idx; i++) {
        cur *= lst[i] + 1;
    }
    
//     for (int i = 1; i < idx; i++) {
//         int cur = lst[i];
//         ans += cur;
//         for (int j = i + 1; j < idx; j++) {
//             cur *= lst[j];
//             ans += cur;
            
//         } 
//         cout << ans << "\n";
        
//     }
    return cur - 1;
}