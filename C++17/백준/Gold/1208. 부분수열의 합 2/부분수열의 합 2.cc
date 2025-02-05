#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#define ll long long
using namespace std;

int N, S;
int lst[40];
vector<ll> L, R;

void getSum(int s, int e, ll sum, vector<ll>& sums) {
    if (s > e) {
        sums.push_back(sum);
        return;
    }
    getSum(s + 1, e, sum, sums);
    getSum(s + 1, e, sum + lst[s], sums);
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> lst[i];

    int mid = N / 2;
    getSum(0, mid - 1, 0, L);
    getSum(mid, N - 1, 0, R);
    sort(R.begin(), R.end());

    ll ans = 0;
    for (ll left_sum : L) {
        ll target = S - left_sum;
        auto upper = upper_bound(R.begin(), R.end(), target);
        auto lower = lower_bound(R.begin(), R.end(), target);
        ans += upper - lower;
    }
    if (S == 0) ans--;
    cout << ans << '\n';
}