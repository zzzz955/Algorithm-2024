#include<iostream>
using namespace std;

int n, ans = 2e9;
int T[5];
struct Skill {
	int ct, dam;
};
Skill skills[5];

void bt(int level, int remain) {
	if (ans <= level) return;
	if (remain <= 0) {
		ans = min(ans, level);
		return;
	}

	bool att = false;
	for (int i = 0; i < n; ++i) {
		if (T[i] > level) continue;
		int curT = T[i];
		att = true;
		T[i] = level + skills[i].ct;
		bt(level + 1, remain - skills[i].dam);
		T[i] = curT;
	}

	if (!att) bt(level + 1, remain);
}

int main() {
	int hp;
	cin >> n >> hp;
	for (int i = 0; i < n; ++i) {
		cin >> skills[i].ct >> skills[i].dam;
	}

	bt(0, hp);
	cout << ans;
}