#include<iostream>
#define ll long long

using namespace std;

const ll MAX_N = 100000;
const ll MOD = 1000000007;
ll nodes[MAX_N];
ll tree[MAX_N * 4];
ll n, m;

struct Lazy {
    ll add = 0;   
    ll mul = 1;   
    ll set = -1;  
};

Lazy lazy[MAX_N * 4];

void build(ll node, ll start, ll end) {
    if (start == end) tree[node] = nodes[start];
    else {
        ll mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
    }
}

void propagate(ll node, ll start, ll end) {
    if (lazy[node].set != -1) {
        tree[node] = (lazy[node].set * (end - start + 1)) % MOD;
        if (start != end) {
            lazy[node * 2].set = lazy[node].set;
            lazy[node * 2 + 1].set = lazy[node].set;
            lazy[node * 2].mul = 1;
            lazy[node * 2 + 1].mul = 1;
            lazy[node * 2].add = 0;
            lazy[node * 2 + 1].add = 0;
        }
        lazy[node].set = -1;
    }

    if (lazy[node].mul != 1) {
        tree[node] = (tree[node] * lazy[node].mul) % MOD;
        if (start != end) {
            lazy[node * 2].mul = (lazy[node * 2].mul * lazy[node].mul) % MOD;
            lazy[node * 2 + 1].mul = (lazy[node * 2 + 1].mul * lazy[node].mul) % MOD;
            lazy[node * 2].add = (lazy[node * 2].add * lazy[node].mul) % MOD;
            lazy[node * 2 + 1].add = (lazy[node * 2 + 1].add * lazy[node].mul) % MOD;
        }
        lazy[node].mul = 1;
    }

    if (lazy[node].add != 0) {
        tree[node] = (tree[node] + lazy[node].add * (end - start + 1)) % MOD;
        if (start != end) {
            lazy[node * 2].add = (lazy[node * 2].add + lazy[node].add) % MOD;
            lazy[node * 2 + 1].add = (lazy[node * 2 + 1].add + lazy[node].add) % MOD;
        }
        lazy[node].add = 0;
    }
}

void update(ll node, ll start, ll end, ll L, ll R, ll idx, ll val) {
    propagate(node, start, end);
    if (R < start || end < L) return;
    if (L <= start && end <= R) {
        if (idx == 1) lazy[node].add = val;
        else if (idx == 2) lazy[node].mul = val;
        else lazy[node].set = val;
        propagate(node, start, end);
        return;
    }
    ll mid = (start + end) / 2;
    update(node * 2, start, mid, L, R, idx, val);
    update(node * 2 + 1, mid + 1, end, L, R, idx, val);
    tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}

ll query(ll node, ll start, ll end, ll L, ll R) {
    propagate(node, start, end);
    if (R < start || end < L) return 0;
    if (L <= start && end <= R) return tree[node] % MOD;
    ll mid = (start + end) / 2;
    ll left = query(node * 2, start, mid, L, R);
    ll right = query(node * 2 + 1, mid + 1, end, L, R);
    return (left + right) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (ll i = 0; i < n; i++) cin >> nodes[i];
    build(1, 0, n - 1);
    cin >> m;
    while (m--) {
        ll a, b, c; cin >> a >> b >> c;
        if (a <= 3) {
            ll d; cin >> d;
            update(1, 0, n - 1, b - 1, c - 1, a, d);
        }
        else cout << query(1, 0, n - 1, b - 1, c - 1) % MOD << "\n";
    }
}