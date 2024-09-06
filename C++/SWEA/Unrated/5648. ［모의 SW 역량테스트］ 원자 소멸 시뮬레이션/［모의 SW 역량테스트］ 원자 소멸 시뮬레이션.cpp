#include<iostream>
#include<vector>
#include<cstring>
#include<set>

using namespace std;
int tc, n, cnt, ans;
int lst[4001][4001];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

struct Atom {
    int x, y, dir, e, life;
};

struct Pos {
    int x, y;
};

vector<Atom> atoms;

void init() {
    cnt = 0;
    ans = 0;
    atoms.clear();
    memset(lst, 0, sizeof(lst));
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, dir, e; cin >> y >> x >> dir >> e;
        x = (x + 1000) * 2;
        y = (y + 1000) * 2;
        atoms.push_back({ x, y, dir, e, 1 });
        lst[x][y] = 1;
        cnt++;
    }
}

void simulation() {
    while (cnt > 0) {
        for (Atom& atom : atoms) {
            if (!atom.life) continue;
            int cx = atom.x, cy = atom.y, cd = atom.dir;
            int nx = cx + dx[cd], ny = cy + dy[cd];
            if (0 <= nx && nx <= 4000 && 0 <= ny && ny <= 4000) {
                lst[nx][ny] += 1;
                lst[cx][cy] -= 1;
                atom.x = nx, atom.y = ny;
            }
            else {
                lst[cx][cy] -= 1;
                atom.life = 0;
                cnt--;
            }
        }
        set<pair<int, int>> pos;
        for (Atom& atom : atoms) {
            if (!atom.life) continue;
            int cx = atom.x, cy = atom.y, ce = atom.e;
            if (lst[cx][cy] > 1) {
                pos.insert({ cx, cy });
                ans += ce;
                atom.life = 0;
                cnt--;
            }
        }
        for (pair<int, int> map : pos) lst[map.first][map.second] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        init();
        input();
        simulation();
        cout << "#" << t << " " << ans << "\n";
    }
}