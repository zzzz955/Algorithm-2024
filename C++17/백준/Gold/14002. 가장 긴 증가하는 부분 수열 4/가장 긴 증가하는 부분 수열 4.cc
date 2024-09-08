#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, nums[1000000], indices[1000000];
vector<int> temp, lis;

void BS() {
    vector<int> pos(n);  // 각 원소가 temp에서 위치한 인덱스를 기록할 배열
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
        int idx = it - temp.begin();

        // temp에 값을 업데이트하거나 추가
        if (it == temp.end()) temp.push_back(nums[i]);
        else *it = nums[i];

        // 해당 숫자가 temp의 어느 위치에 들어갔는지 기록
        pos[i] = idx;
    }

    // LIS 길이를 미리 저장
    int length = temp.size();
    cout << length << "\n";

    // LIS를 복원하기 위한 역추적
    int currentLength = length - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (pos[i] == currentLength) {
            lis.push_back(nums[i]);
            currentLength--;
        }
    }

    // LIS를 뒤집어서 출력
    reverse(lis.begin(), lis.end());
    for (int l : lis) cout << l << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    BS();
}
