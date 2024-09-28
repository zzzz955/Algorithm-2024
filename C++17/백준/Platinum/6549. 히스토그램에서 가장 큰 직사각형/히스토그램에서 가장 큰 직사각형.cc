#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;
ll lst[100000];
ll tree[400000];
ll n, ans;

void init() {
    memset(lst, 0, sizeof(lst));
    memset(tree, 0, sizeof(tree));
    ans = 0;
}

void input() {
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
        ans = max(ans, lst[i]);
    }
}

void build(ll node, ll start, ll end) {
    if (start == end) tree[node] = start;
    else {
        ll mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree[node] = (lst[tree[node * 2]] <= lst[tree[node * 2 + 1]]) ? tree[node * 2] : tree[node * 2 + 1];
    }
}

ll getIndex(ll node, ll start, ll end, ll L, ll R) {
    if (R < start || end < L) return -1;
    if (L <= start && end <= R) return tree[node];
    ll mid = (start + end) / 2;
    ll left = getIndex(node * 2, start, mid, L, R);
    ll right = getIndex(node * 2 + 1, mid + 1, end, L, R);

    if (left == -1) return right;
    if (right == -1) return left;
    return (lst[left] <= lst[right]) ? left : right;
}

ll query(ll start, ll end) {
    if (start > end) return 0;
    ll min_index = getIndex(1, 0, n - 1, start, end);
    ll all = lst[min_index] * (end - start + 1);
    ll left = query(start, min_index - 1);
    ll right = query(min_index + 1, end);

    return max({ all, left, right });
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> n;
        if (!n) break;
        init();
        input();
        build(1, 0, n - 1);
        cout << query(0, n - 1) << "\n";
    }
}