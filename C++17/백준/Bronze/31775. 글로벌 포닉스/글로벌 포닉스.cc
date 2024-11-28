#include <iostream>
using namespace std;

int v[100];

int main() {
    for (int i = 0; i < 3; ++i) {
        string s; cin >> s;
        v[s[0]] = 1;
    }
    if (v['p'] && v['l'] && v['k']) cout << "GLOBAL";
    else cout << "PONIX";
}