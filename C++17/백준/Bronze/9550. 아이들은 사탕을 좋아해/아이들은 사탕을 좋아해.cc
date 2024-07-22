#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        while (n--) {
            int c;
            cin >> c;
            cnt += c / k;
        }
        cout << cnt << "\n";
    }
}
