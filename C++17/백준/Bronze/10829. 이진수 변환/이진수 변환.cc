#include <iostream>
#include <string>

using namespace std;

int main() {
    long long n;
    cin >> n;
    string ans = "";

    for (int i = 46; i >= 0; i--) {
        long long power = 1LL << i;
        if (n - power >= 0) {
            n -= power;
            ans += '1';
        }
        else {
            if (!ans.empty()) {
                ans += '0';
            }
        }
    }

    if (ans.empty()) {
        cout << '0';
    }
    else {
        cout << ans;
    }
}
