#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> lst(n);
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }
    int h;
    cin >> h;
    if (h == 1) {
        for (int i = 0; i < n; i++) {
            cout << lst[i] << "\n";
        }
    }
    else if (h == 2) {
        for (int i = 0; i < n; i++) {
            reverse(lst[i].begin(), lst[i].end());
            cout << lst[i] << "\n";
        }
    }
    else {
        for (int i = n - 1; i >= 0; i--) {
            cout << lst[i] << "\n";
        }
    }
}
