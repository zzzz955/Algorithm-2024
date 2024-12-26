#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, k, ans;
int nodes[51];
vector<int> parties[51];

// 유니온-파인드 함수
int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A == B) return;
	nodes[B] = A;
}

// 그룹 번호가 낮은 순서로 정렬하기 위한 커스텀 정렬 함수
bool compare(int a, int b) {
	return Find(nodes[a]) < Find(nodes[b]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	// 1 ~ n번 까지의 사람의 속한 그룹을 자기 자신으로 초기화
	for (int i = 1; i <= n; ++i) nodes[i] = i;

	// k명의 사람은 진실을 알고있음을 명시, 0번 그룹인 사람들은 진실을 알고 있는 사람들의 그룹으로 가정
	cin >> k;
	while (k--) {
		int a; cin >> a;
		// a번의 사람의 value를 0으로 바꿔줌으로 진실을 아는 그룹에 속하도록 변경
		nodes[a] = 0;
	}

	// m개의 파티 정보를 입력 받음
	for (int i = 0; i < m; ++i) {
		// i번 파티에 참여한 a명의 참여자를 parties의 i번째 벡터에 추가
		int a; cin >> a;
		while (a--) {
			int b; cin >> b;
			parties[i].push_back(b);
		}

		// nodes배열의 value가 낮은 순으로 정렬, value가 0인 경우(진실을 아는 경우) 맨 앞으로 오게 됨
		sort(parties[i].begin(), parties[i].end(), compare);

		// nodes배열의 value가 가장 낮은 한명을 기준으로 파티에 참여한 인원 모두 그룹화를 진행
		// 만약 진실을 아는 사람이 있을 경우 해당 파티에 속한 인원은 모두 진실을 알게 된다.
		for (int j = 1; j < parties[i].size(); ++j) Union(parties[i][0], parties[i][j]);
	}

	// m개의 파티 정보를 다시 순회하며 현재 파티에 진실을 아는 사람이 존재하는지 체크
	for (int i = 0; i < m; ++i) {
		bool flag = 1;

		// 파티 참여 인원을 모두 체크
		for (int j = 0; j < parties[i].size(); ++j) {
			// 그룹이 0번인 사람이 있을 경우 해당 파티는 pass
			if (!Find(parties[i][j])) {
				flag = 0;
				//break;
			}
		}
		if (flag) ans++;
	}
	cout << ans;
}