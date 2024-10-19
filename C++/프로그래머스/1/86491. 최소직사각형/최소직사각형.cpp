#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int n = sizes.size();
    
    int w = 0, h = 0;
    for (vector<int> size:sizes) {
        if (size[0] < size[1]) swap(size[0], size[1]);
        w = max(w, size[0]);
        h = max(h, size[1]);
    }
    
    return w * h;
}