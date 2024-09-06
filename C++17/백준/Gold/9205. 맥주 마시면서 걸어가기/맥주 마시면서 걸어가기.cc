#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
int tc, n, dx, dy, length;
int v[103]; // 최대 편의점 개수

struct Pos {
	int x, y;
};
vector<Pos> path; // 인접 리스트
vector<string> ans;

void init() { // 초기화 함수
	path.clear();
	memset(v, 0, sizeof(v));
}

void input() { // 입력 받기
	cin >> n;
	for (int i = 0; i < n + 2; i++) { // 시작지점 + 편의점 + 도착지점
		int x, y; cin >> x >> y;
		path.push_back({ x, y });
	}
	length = n + 2;
}

int calc_dist(int x1, int y1, int x2, int y2) { // 거리 계산 함수
	return abs(x1 - x2) + abs(y1 - y2);
}

bool bfs() {
	queue<Pos> q;
	q.push({ path[0] }); // 시작 지점 큐에 추가
	v[0] = 1;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;

		for (int i = 0; i < length; i++) { // 인접리스트 탐색
			if (v[i]) continue;
			Pos next = path[i];
			int nx = next.x, ny = next.y;
			int dist = calc_dist(cx, cy, nx, ny);
			if (1000 >= dist) { // 현재 좌표에서 다음 좌표까지 갈 수 있는고?
				if (i == length - 1) return true; // 도착지점이면 리턴
				v[i] = 1;
				q.push({ nx, ny });
			}
		}
	}
	return false; // 도착지점까지 가지 못했음
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		init();
		input();
		if (bfs()) ans.push_back("happy");
		else ans.push_back("sad");
	}
	for (string s : ans) cout << s << "\n";
}