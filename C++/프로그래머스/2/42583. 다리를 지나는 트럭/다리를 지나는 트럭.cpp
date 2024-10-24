#include <bits/stdc++.h>

using namespace std;

struct Brid {
    int w, it;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int cur = 0, w = 0, run = 0;
    queue<Brid> q;
    for (int i = 0; i < truck_weights.size(); i++) {
        int now = truck_weights[i];
        
        if (cur >= q.front().it + bridge_length) {
            w -= q.front().w;
            run--;
            q.pop();
        }
        
        while (w + now > weight || run == bridge_length) {
            Brid brid = q.front(); q.pop();
            cur = brid.it + bridge_length - 1;
            w -= brid.w;
            run--;
        }
        
        cur++;
        run++;
        q.push({now, cur});
        w += now;
        cout << cur << " ";
    }
    
    while (!q.empty()) {
        Brid brid = q.front(); q.pop();
        cur = brid.it + bridge_length;
        w -= brid.w;
    }
    
    return cur;
}