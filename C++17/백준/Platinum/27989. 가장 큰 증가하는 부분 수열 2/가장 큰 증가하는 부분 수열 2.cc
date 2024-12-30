#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long
#define MAX 300000

using namespace std;

int n;
ll lst[MAX];
ll tree[4 * MAX];  // 세그먼트 트리
vector<ll> compressed;  // 좌표 압축을 위한 벡터

// 세그먼트 트리의 최대값 쿼리
ll query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;  // 범위 밖
    if (left <= start && end <= right) return tree[node];  // 범위 안
    int mid = (start + end) / 2;
    return max(query(node * 2, start, mid, left, right),
        query(node * 2 + 1, mid + 1, end, left, right));
}

// 세그먼트 트리 업데이트
void update(int node, int start, int end, int idx, ll value) {
    if (start == end) {
        tree[node] = value;
    }
    else {
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(node * 2, start, mid, idx, value);
        else
            update(node * 2 + 1, mid + 1, end, idx, value);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> lst[i];
        compressed.push_back(lst[i]);
    }

    // 1. 좌표 압축
    sort(compressed.begin(), compressed.end());
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());
    map<ll, int> compress_idx;
    for (int i = 0; i < compressed.size(); ++i) {
        compress_idx[compressed[i]] = i + 1;  // 1-based index
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int idx = compress_idx[lst[i]];
        // 2. 쿼리: lst[i]보다 작은 값들의 최대 합을 찾기
        ll max_sum = query(1, 1, compressed.size(), 1, idx - 1);
        ll new_sum = max_sum + lst[i];
        // 3. 업데이트: lst[i]의 위치에 새로운 합으로 갱신
        update(1, 1, compressed.size(), idx, new_sum);
        ans = max(ans, new_sum);
    }

    cout << ans << '\n';
}
