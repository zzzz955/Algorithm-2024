#include <bits/stdc++.h>

using namespace std;

int n, ans = 1e9;
int v[20];

void bt(int index, int turn, string str, const string& name) {
    if (str[index] != name[index]) {
        turn += min(abs(str[index] - name[index]), abs(str[index] - 'A' + 'Z' - name[index]) + 1);
        str[index] = name[index];
    }
    
    if (str == name) {
        ans = min(ans, turn);
        return;
    }
    
    int tn = n, l = index - 1, r = index + 1, mt = 1;
    while (tn--) {
        if (l == -1) l = n - 1;
        if (r == n) r = 0;
        if (str[l] != name[l]) bt(l, turn + mt, str, name);
        if (str[r] != name[r]) bt(r, turn + mt, str, name);
        mt++;
        l--;
        r++;
    }
}

int solution(string name) {
    n = name.size();
    string s = "";
    for (int i = 0; i < n; i++) s += "A";
    
    bt(0, 0, s, name);
    cout << min(abs('E' - 'T'), abs('A' - 'A' + 'Z' - 'Z'));
    
    return ans;
}