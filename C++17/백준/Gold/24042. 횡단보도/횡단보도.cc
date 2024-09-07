#include<iostream>
#include<queue>
#define ll long long

using namespace std;

int n, m;
ll dist[100001];

struct Pos { // 다익스트라용 구조체
	ll t; // 시간
	int node; // 현재 노드
	bool operator<(const Pos& other) const { // 시간 순으로 compare
		return t > other.t;
	}
};

struct EDGE { // 인접 리스트용 구조체
	int next, idx; // 다음 노드, 초록불이 열리는 인덱스
};

vector<vector<EDGE>> path; // 인접 리스트

long long dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 0, 1 }); // 1부터 시작
	dist[1] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		ll ct = pos.t; // 현재 시간
		int cn = pos.node; // 현재 노드

		if (ct != dist[cn]) continue; // 이미 더 빠른 값이 들와 있는 경우

		for (EDGE edge : path[cn]) { // 인접 리스트 탐색
			// green = 해당 노드의 신호등이 켜지는 인덱스, nn = 해당 노드, md = 현재 시간을 m값으로 나눈 값 (인덱스 비교용)
			int green = edge.idx, nn = edge.next, md = ct % m; 
			ll nt = ct; // 우선 현재시간과 동일하게 적용
			if (md != green) { // 신호등에 불이 켜져있는지 체크
				if (md < green) nt += green - md; // 한바퀴 돌 필요가 없는경우
				else nt += m - md + green; // 한바퀴 돌아야 하는 경우
			}
			if (dist[nn] > nt + 1) { // 최대값 계산
				dist[nn] = nt + 1;
				pq.push({ nt + 1, nn });
			}
		}
	}
	return dist[n]; // n번째 노드까지의 최소 거리 출력
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	path.resize(n + 1);
	for (int i = 1; i <= n; i++) dist[i] = 1e18; // 최대한 큰값으로 설정
	for (int i = 0; i < m; i++) { // 양방향 간선 추가
		int a, b; cin >> a >> b;
		path[a].push_back({ b, i });
		path[b].push_back({ a, i });
	}
	cout << dijkstra();
}