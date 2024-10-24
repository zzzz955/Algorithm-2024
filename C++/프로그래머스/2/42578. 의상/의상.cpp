#include <bits/stdc++.h>
using namespace std;

int ans = 0, idx = 1;
int lst[31]; // 각 카테고리별 의상 개수를 저장하는 배열
int v[31];   // 각 의상 카테고리를 방문했는지 확인하는 배열
unordered_map<string, int> dic; // 의상 카테고리명을 저장

// 백트래킹 함수
void bt(int level, int val, int last) {
    if (level) ans += val; // 최소 하나 이상의 의상을 선택한 경우에만 계산
    if (level == idx) return; // 모든 카테고리를 탐색하면 종료

    // 의상 카테고리별로 하나씩 선택
    for (int i = last + 1; i < idx; i++) { // last 이후부터 탐색하여 중복 방지
        if (v[i]) continue;  // 이미 선택한 카테고리는 건너뛰기
        v[i] = 1;  // 해당 카테고리를 선택
        bt(level + 1, val * lst[i], i); // 다음 카테고리로 백트래킹 진행
        v[i] = 0;  // 선택 해제 (백트래킹에서 되돌아오면 초기화)
    }
}

int solution(vector<vector<string>> clothes) {
    for (auto cloth : clothes) {
        if (!dic[cloth[1]]) {  // 새로운 카테고리일 경우
            lst[idx]++;        // 해당 카테고리의 의상 개수 증가
            dic[cloth[1]] = idx++; // 카테고리 인덱스를 저장
        } else {
            lst[dic[cloth[1]]]++; // 이미 있는 카테고리일 경우 개수 증가
        }
    }
    
    bt(0, 1, 0); // 백트래킹 호출 (초기값으로 level 0, 곱셈 1, 마지막 선택 0)
    
    return ans; // 모든 경우의 수를 반환
}
