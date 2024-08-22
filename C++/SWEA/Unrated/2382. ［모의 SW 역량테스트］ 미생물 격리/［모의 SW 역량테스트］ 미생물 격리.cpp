#include<iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

int lst[100][100];
int t, n, m, k, ans;

int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };

struct BUG {
	int x, y, c, d, idx;
};

BUG bugs[1001];
vector<int> Union[100][100];
queue<int> q;

void init() {
	ans = 0;
	memset(lst, 0, sizeof(lst));
}

void input() {
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		bugs[i] = { a, b, c, d, i }; // 미생물 정보 받아오고 배열에 저장
		lst[a][b] = i; // 맵에는 해당 미생물의 인덱스 배치
	}
}

void doUnion() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!Union[i][j].empty()) {
				int max_cc = 0, sum_cc = 0, max_idx = 0;
				for (k = 0; k < Union[i][j].size(); k++) {
					BUG& bug = bugs[Union[i][j][k]];
					if (max_cc < bug.c) {
						max_cc = bug.c;
						max_idx = bug.idx;
					}
					sum_cc += bug.c;
				}
				BUG& bug = bugs[max_idx];
				lst[i][j] = bug.idx;
				bug.x = i, bug.y = j, bug.c = sum_cc;
				Union[i][j].clear();
			}
		}
	}
	
}

void bfs() {
	while (!q.empty()) { // 미생물이 큐에 남아있지 않을 때 까지 이동 시작
		int index = q.front(); q.pop();
		BUG& bug = bugs[index]; // 미생물의 주소 참조
		int cd = bug.d, cc = bug.c, ci = bug.idx;
		int nx = bug.x + dx[cd], ny = bug.y + dy[cd]; // 현재 미생물의 방향으로 한칸 이동
		if (nx == 0 || ny == 0 || nx == n - 1 || ny == n - 1) { // 벽에 닿은 경우
			cc /= 2; // 군집 수 절반으로 줄임
			if (cd % 2) cd += 1; // 반대 방향으로 변환
			else cd -= 1;
		}
		Union[nx][ny].push_back(ci);
		bug.x = nx, bug.y = ny, bug.c = cc, bug.d = cd; // 현재 미생물 주소값 업데이트
	}
	doUnion();
}

void solution() {
	while (m--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (lst[i][j]) { // 미생물 싹다 긁어다가 큐에 해당 미생물의 인덱스 추가
					q.push({ lst[i][j] });
					lst[i][j] = 0; // 맵 다시 싹 0으로 만들기
				}
			}
		}
		bfs(); // 미생물 이동 시작
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (lst[i][j]) ans += bugs[lst[i][j]].c; // 현재 맵에 남아있는 미생물의 개수 카운트
		}
	}
}

int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		init(); // 초기화
		input(); // 입력
		solution(); // 시뮬레이션
		cout << "#" << tc << " " << ans << "\n";
	}
}