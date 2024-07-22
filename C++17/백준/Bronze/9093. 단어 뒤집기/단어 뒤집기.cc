#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);

        string ans;
        string temp;

        for (char c : s) {
            if (c == ' ') {
                reverse(temp.begin(), temp.end());
                ans += temp + ' ';
                temp.clear();
            }
            else {
                temp += c;
            }
        }

        reverse(temp.begin(), temp.end());
        ans += temp;

        cout << ans << "\n";
    }

    return 0;
}
