#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int lst[1001];
int t, n;

struct Team {
	int cnt, index;
	vector<int> points;
};
Team teams[201];

void init() {
	for (int i = 1; i < 201; i++) {
		Team& team = teams[i];
		team.cnt = 0;
		team.index = 0;
		team.points.clear();
	}
}

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int team; cin >> team;
		lst[i] = team;
		teams[team].cnt++;
		if (teams[team].cnt == 5) teams[team].index = i;
	}
}

void solution() {
	int point = 1;
	for (int i = 1; i <= n; i++) {
		if (teams[lst[i]].cnt < 6) continue;
		teams[lst[i]].points.push_back(point);
		point++;
	}
	int min_val = 1e9, min_idx = 0;
	for (int i = 1; i < 201; i++) {
		if (teams[i].cnt < 6) continue;
		vector<int>& players = teams[i].points;
		sort(players.begin(), players.end());
		int min_points = 0;
		for (int j = 0; j < 4; j++) min_points += players[j];
		if (min_val == min_points) {
			if (teams[min_idx].index > teams[i].index) min_idx = i;
		}
		else if (min_val > min_points) {
			min_val = min_points;
			min_idx = i;
		}
	}
	cout << min_idx << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		init();
		input();
		solution();		
	}
}