#include <bits/stdc++.h>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    int l = 1;
    int r = distance;
    sort(rocks.begin(), rocks.end());
    
    while (l <= r) {
        int mid = (l + r) / 2;
        int cur = 0;
        int remove = 0;
        
        for (int rock : rocks) {
            if (cur + mid > rock) remove += 1;
            else cur = rock;
        }
        
        if (cur + mid > distance) remove += 1;
        
        if (remove <= n) {
            answer = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    
    return answer;
}