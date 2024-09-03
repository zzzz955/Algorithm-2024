#include<iostream>
#include<deque>
#include<cstring>
#include<cmath>

using namespace std;

int tc, k, ans = 0;
deque<int> mag[5];
int v[5];

void input() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 8; j++) {
            char a; cin >> a;
            mag[i].push_back({ a - '0' });
        }
    }
}

void bt(int index, int dir) {
    if (1 < index && !v[index - 1]) {
        v[index - 1] = 1;
        if (mag[index - 1][2] != mag[index][6]) {
            bt(index - 1, dir * -1);
        }
    }
    if (index < 4 && !v[index + 1]) {
        v[index + 1] = 1;
        if (mag[index][2] != mag[index + 1][6]) {
            bt(index + 1, dir * -1);
        }
    }
    if (dir == 1) {
        mag[index].push_front(mag[index].back());
        mag[index].pop_back();
    }
    else {
        mag[index].push_back(mag[index].front());
        mag[index].pop_front();
    }
}

void solution() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        memset(v, 0, sizeof(v));
        v[a] = 1;
        bt(a, b);
    }
    for (int i = 1; i <= 4; i++) {
        ans += mag[i].front() * pow(2, i - 1);
    }
}

int main() {
    input();
    solution();
    cout << ans;
}