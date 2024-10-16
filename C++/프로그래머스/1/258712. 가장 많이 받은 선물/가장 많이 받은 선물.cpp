#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    unordered_map<string, int> dic;
    int n = friends.size();
    for (int i = 0; i < n; i++) dic[friends[i]] = i;
    
    vector<vector<int>> lst(n, vector<int>(n, 0));
    int m = gifts.size();
    for (int i = 0; i < m; i++) {
        string s = gifts[i];
        auto it = find(s.begin(), s.end(), ' ');
        string a = string(s.begin(), it), b = string(++it, s.end());
        int x = dic[a], y = dic[b];
        lst[x][y]++;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << lst[i][j] << " ";
        }
        cout << "\n";
    }
    
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt[i] += lst[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt[i] -= lst[j][i];
        }
    }
    
    for (int i = 0; i < n; i++) cout << cnt[i] << " ";
    
    vector<int> nextmonth(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            else if (lst[i][j] > lst[j][i]) nextmonth[i]++;
            else if (lst[i][j] == lst[j][i]) {
                if (cnt[i] > cnt[j]) nextmonth[i]++;
            }
        }
    }
    
    int max_val = 0;
    for (int i:nextmonth) max_val = max(max_val, i);
    
    return max_val;
}