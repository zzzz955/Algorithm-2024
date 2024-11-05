#include<iostream>
#include<algorithm>
using namespace std;

int dx[] = {0, 0, 0, -1, 1 };
int dy[] = {0, 1, -1, 0, 0 };

int n, m, sx, sy, k;
int lst[20][20];
int dice[7];
int rev[7] = { 0, 6, 5, 4, 3, 2, 1 };
int status[4][3] = {
	{0, 2, 0},
	{4, 1, 3},
	{0, 5, 0},
	{0, 6, 0}
};

void roll(int order) {
	if (order == 1) {
		swap(status[3][1], status[1][0]);
		swap(status[1][0], status[1][1]);
		swap(status[1][1], status[1][2]);
	}
	else if (order == 2) {
		swap(status[3][1], status[1][2]);
		swap(status[1][2], status[1][1]);
		swap(status[1][1], status[1][0]);
	}
	else if (order == 3) {
		swap(status[3][1], status[2][1]);
		swap(status[2][1], status[1][1]);
		swap(status[1][1], status[0][1]);
	}
	else {
		swap(status[3][1], status[0][1]);
		swap(status[0][1], status[1][1]);
		swap(status[1][1], status[2][1]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> sx >> sy >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			cin >> lst[i][j];

	int floor = 1;
	//dice[floor] = lst[0][0];
	//lst[0][0] = 0;
	while (k--) {
		int order; cin >> order;
		int nx = sx + dx[order], ny = sy + dy[order];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			sx = nx, sy = ny;
			roll(order);
			floor = status[1][1];
			//cout << floor << "\n";
			if (lst[nx][ny]) {
				dice[floor] = lst[nx][ny];
				lst[nx][ny] = 0;
			}
			else lst[nx][ny] = dice[floor];

			cout << dice[rev[floor]] << "\n";
		}
	}
}
