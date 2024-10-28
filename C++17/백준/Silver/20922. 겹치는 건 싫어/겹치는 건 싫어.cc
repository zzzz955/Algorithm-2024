#include<iostream>
#include<cstring>
using namespace std;

int v[100001];
int lst[200000];
int n, k, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> lst[i];

	int l = 0, r = 0, cnt = 0;
	while (r < n) { // lst의 끝까지 탐색
		v[lst[r]]++; // r의 위치에 있는 수의 개수 증가
		cnt++; // 총 수열의 길이 증가
		while (v[lst[r]] > k) { // 만약 lst[r]이 k개를 넘어섰다면
			v[lst[l]]--;
			l++;
			cnt--;
		}
		r++;
		ans = max(ans, cnt); // ans 최신화
	}
	cout << ans;
}