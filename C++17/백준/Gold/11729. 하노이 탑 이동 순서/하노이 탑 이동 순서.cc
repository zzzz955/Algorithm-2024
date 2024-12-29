#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> path;

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        path.push_back({ from, to });
        return;
    }

    hanoi(n - 1, from, aux, to);
    path.push_back({ from, to });
    hanoi(n - 1, aux, to, from);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    hanoi(n, 1, 3, 2);
    cout << path.size() << "\n";
    for (const auto& i : path) cout << i.first << " " << i.second << "\n";

    return 0;
}
