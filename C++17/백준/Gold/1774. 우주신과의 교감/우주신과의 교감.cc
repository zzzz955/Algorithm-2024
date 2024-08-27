#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cmath>

using namespace std;

int n, m, n1, n2; 
int nodes[1001]; // 노드 배열

struct Pos {
	int x, y;
};

Pos pos[1001]; // 노드의 좌표 배열

int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

void Union(int a, int b) {
	int rootA = Find(a);
	int rootB = Find(b);
	if (rootA == rootB) return;
	nodes[rootB] = rootA;
}

double calcdist(int x1, int y1, int x2, int y2) { // 두 좌표의 거리 구하기
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		pos[i] = { x, y }; // 노드 좌표 저장
		nodes[i] = i; // 노드 초기화
	}

	double total = 0; // 거리 토탈
	for (int i = 0; i < m; i++) { // 이미 연결된 케이스
		cin >> n1 >> n2;
		Union(n1, n2); // 집합을 합쳐준다.
	}

	vector<tuple<double, int, int>> edges; // 간선 및 간선 간 거리 구하기
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			double dist = calcdist(pos[i].x, pos[i].y, pos[j].x, pos[j].y);
			edges.push_back({ dist, i, j });
		}
	}
	sort(edges.begin(), edges.end()); // 오름차순 정렬

	for (int i = 0; i < edges.size(); i++) { // MST 구하기
		double d = get<0>(edges[i]);
		int a = get<1>(edges[i]), b = get<2>(edges[i]);
		if (Find(a) == Find(b)) continue;
		Union(a, b);
		total += d;
	}
	printf("%.2f", total); // 소숫점 두자리 까지 출력
}