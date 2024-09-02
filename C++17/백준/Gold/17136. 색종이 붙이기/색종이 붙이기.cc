#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int lst[10][10];
int ans = 1e9; // 최대값 설정
int one = 0; // 1의 개수 저장용
int papers[6]; // 색종이 정보
int v[6] = { 0, }; // 방문처리용

void input() { // 맵 초기화, 1의 총 개수 초기화, 색종이 개수 초기화
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> lst[i][j];
            if (lst[i][j]) one++;
        }
    }
    for (int i = 1; i < 6; i++) papers[i] = 5;
}

bool chk(int index, int x, int y) { // index * index 색종이를 붙힐 수 있는지 체크
    for (int i = x; i < x + index; i++) {
        for (int j = y; j < y + index; j++) {
            if (!lst[i][j]) return false;
        }
    }
    return true;
}

void simul(int index, int x, int y) {
    for (int i = x; i < x + index; i++) {
        for (int j = y; j < y + index; j++) {
            lst[i][j] = 0;
        }
    }
}

void resimul(int index, int x, int y) {
    for (int i = x; i < x + index; i++) {
        for (int j = y; j < y + index; j++) {
            lst[i][j] = 1;
        }
    }
}

void dfs(int x, int total, int remain) { // 모든 색종이 사용해 보기
    if (!remain) { // 더 이상 1이 없다면 최소값 갱신 후 리턴
        ans = min(ans, total);
        return;
    }
    if (ans <= total || total > 25) return;
    for (int row = x; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            if (lst[row][col]) {
                for (int i = 5; i > 0; i--) { // 색종이 1 ~ 5 전부 중복 없이 사용해 보기
                    if (row + i <= 10 && col + i <= 10 && papers[i] && chk(i, row, col)) {
                        simul(i, row, col);
                        papers[i]--;
                        dfs(row, total + 1, remain - (i * i)); // 1을 0으로 바꾼 개수만큼 remain에서 빼준다.
                        resimul(i, row, col);
                        papers[i]++;
                    }
                }
                return;
            }
        }
    }
}

int main() {
    input();
    dfs(0, 0, one);
    if (ans == 1e9) cout << -1;
    else cout << ans;
}