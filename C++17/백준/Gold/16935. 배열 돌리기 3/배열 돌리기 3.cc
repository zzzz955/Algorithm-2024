#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, m, r;
vector<vector<int>> lst;

void rotate(int a) {
	vector<vector<int>> result;
	if (a == 1) {
		result.resize(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				result[n - i - 1][j] = lst[i][j];
			}
		}
	}
	else if (a == 2) {
		result.resize(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				result[i][m - j - 1] = lst[i][j];
			}
		}
	}
	else if (a == 3) {
		result.resize(m, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				result[j][n - i - 1] = lst[i][j];
			}
		}
		swap(n, m);
	}
	else if (a == 4) {
		result.resize(m, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				result[m - j - 1][i] = lst[i][j];
			}
		}
		swap(n, m);
	}
	else if (a == 5) {
		result.resize(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i < n / 2 && j < m / 2) {
					result[i][j + m / 2] = lst[i][j];
				}
				else if (i < n / 2 && j >= m / 2) {
					result[i + n / 2][j] = lst[i][j];
				}
				else if (i >= n / 2 && j >= m / 2) {
					result[i][j - m / 2] = lst[i][j];
				}
				else if (i >= n / 2 && j < m / 2) {
					result[i - n / 2][j] = lst[i][j];
				}
			}
		}
	}
	else {
		result.resize(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i < n / 2 && j < m / 2) {
					result[i + n / 2][j] = lst[i][j];
				}
				else if (i < n / 2 && j >= m / 2) {
					result[i][j - m / 2] = lst[i][j];
				}
				else if (i >= n / 2 && j >= m / 2) {
					result[i - n / 2][j] = lst[i][j];
				}
				else if (i >= n / 2 && j < m / 2) {
					result[i][j + m / 2] = lst[i][j];
				}
			}
		}
	}
	lst = result;
}

void input() {
	cin >> n >> m >> r;
	lst.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lst[i][j];
		}
	}
}

void query() {
	while (r--) {
		int a; cin >> a;
		rotate(a);
	}
}

void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << lst[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	query();
	output();
}