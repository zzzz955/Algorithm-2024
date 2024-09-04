#include<iostream>
#include<vector>

using namespace std;

int N;
int arr[10];
int visited[10];
int factorial[10] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int twon[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
int ans, cnt, total;
vector<int> path, LeftChoo, RightChoo;

void init() {
	ans = 0;
	cnt = 0;
	total = 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		total += arr[i];
	}
}

void dfs(int now, int left, int right) {
	if (now == N) {
		cnt++;
		return;
	}
	if (total - left <= left) {
		cnt += factorial[N - now] * twon[N - now];
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i])continue;
		visited[i] = 1;
		dfs(now + 1, left + arr[i], right);
		visited[i] = 0;
		if (left < right + arr[i]) continue;
		visited[i] = 1;
		dfs(now + 1, left, right + arr[i]);
		visited[i] = 0;
	}
}

void solution() {
	dfs(0, 0, 0);
	ans = cnt;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solution();
		cout << "#" << tc << " " << ans << "\n";
	}
}