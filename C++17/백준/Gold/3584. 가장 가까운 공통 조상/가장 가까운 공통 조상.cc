#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX_N = 10001;
const int LOG = 15;
int parent[MAX_N][LOG];
vector<int> tree[MAX_N];
int nodes[MAX_N];
int depth[MAX_N];
int tc, n, root;

void init() { // n, root, tree 초기화
	cin >> n;
	root = -1;
	for (int i = 0; i < MAX_N; i++) tree[i].clear();
	memset(parent, 0, sizeof(parent));
}

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

void dfs(int node, int par, int dep) { // 각 노드의 바로 위 부모 노드 초기화(연결리스트 활용)
	parent[node][0] = par;
	depth[node] = dep;
	for (int child : tree[node]) {
		if (child != par) dfs(child, node, dep + 1);
	}
}

void preprocess() { // 각 노드의 모든 부모 초기화 (없을 경우 -1)
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			if (parent[i][j - 1] != -1) parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

int lca(int u, int v) { // u와 v의 최소 부모 노드 찾기
	if (depth[u] < depth[v]) swap(u, v); // u가 더 깊게끔 해준다.
	int diff = depth[u] - depth[v]; // 깊이 차이 계산

	for (int i = 0; i < LOG; i++) { // 깊이 차이만큼 u를 상위 노드로 올려준다.
		if ((diff >> i) & 1) u = parent[u][i];
	}

	if (u == v) return u; // v가 u의 부모일 경우 리턴

	for (int i = LOG - 1; i >= 0; i--) {
		if (parent[u][i] != parent[v][i]) { // 부모가 다를 경우 깊이를 2^i씩 높여준다.
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	return parent[u][0]; // 노드의 바로 위 부모 노드를 반환
}

int main() {
	cin >> tc;
	while (tc--) {
		init(); // 초기화
		for (int i = 1; i <= n; i++) nodes[i] = i; // 유니온 파인드용 노드 배열 초기화
		for (int i = 0; i < n - 1; i++) { // 인접리스트 받아오기 & 유니온 처리하기
			int a, b; cin >> a >> b;
			tree[a].push_back(b);
			tree[b].push_back(a);
			Union(a, b);
		}
		for (int i = 1; i <= n; i++) { // 루트 노드를 찾는다.
			//cout << i << " " << nodes[i] << "\n";
			if (nodes[i] == i) {
				//cout << "ROOT : " << i << "\n";
				root = i;
				break;
			}
		}
		int n1, n2; cin >> n1 >> n2;
		dfs(root, -1, 0); // 루트를 기준으로 dfs 실행
		preprocess();
		cout << lca(n1, n2) << "\n";
	}
}