#include <bits/stdc++.h>

using namespace std;

int nodes[200];

int Find(int a) {
    if (nodes[a] == a) return a;
    return nodes[a] = Find(nodes[a]);
}

void Union(int a, int b) {
    int A = Find(a);
    int B = Find(b);
    if (A == B) return;
    nodes[B] = A;
}

int solution(int n, vector<vector<int>> computers) {
    vector<vector<int>> lst(n);
    
    for (int i = 0; i < n; i++) nodes[i] = i;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (computers[i][j]) Union(i, j);
        }
    }
    
    unordered_set<int> dic;
    for (int i = 0; i < n; i++) if (nodes[i] == i) dic.insert(i);
    return dic.size();
}