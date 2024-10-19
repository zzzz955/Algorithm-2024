#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll solution(int n, vector<int> times) {
    ll answer = 0;
    
    ll left = 1;
    int max_t = 0;
    for (int i:times) max_t = max(max_t, i);
    ll right = (ll)max_t * n;
    
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll total = 0;
        
        for (int i:times) total += mid / i;
        
        if (total < n) left = mid + 1;
        else {
            answer = mid;
            right = mid - 1;
        }
    }
    
    return answer;
}