#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d = 0, p = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (abs(d - p) < 2) {
            if (c == 'D') d++;
            else if (c == 'P') p++;
        }
    }

    cout << d << ":" << p;
}
