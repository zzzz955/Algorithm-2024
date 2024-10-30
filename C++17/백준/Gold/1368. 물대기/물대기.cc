#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge {
	int cn, nn, val;
	bool operator<(const Edge& other) const { // val기준 오름차순 정렬 cmp 함수
		return val < other.val;
	}
};

int n;
int nodes[301]; // 직접 우물을 팔때의 비용
int groups[301]; // 유니온-파인드용 그룹 짓기 배열
vector<Edge> edges; // 간선 정보

int Find(int a) {
	if (groups[a] == a) return a;
	return groups[a] = Find(groups[a]);
}

bool Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A == B) return false;
	groups[B] = A;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		groups[i] = i; // 그룹 정보 초기화
		cin >> nodes[i]; // 우물 비용 초기화
		edges.push_back({ 0, i, nodes[i] });
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int w; cin >> w;
			if (i == j || w<=0) continue;
			edges.push_back({ i, j, w }); // 양방향 간선 추가
		}
	}
	sort(edges.begin(), edges.end()); // 가중치 기준 간선 오름차순 정렬

	int sum = 0;
	for (const Edge& edge : edges) {
		int cn = edge.cn, nn = edge.nn, val = edge.val;
		if (Union(cn, nn)) sum += val; // 논 연결 했으면 가중치 sum에 추가
	}
	cout << sum;
}