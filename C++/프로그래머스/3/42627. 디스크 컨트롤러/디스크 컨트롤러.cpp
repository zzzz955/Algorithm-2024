#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct order { // 종료시간 기준 오름차순 pq2용
    int s, r;
    bool operator<(const order& other) const {
        if (r == other.r) return s > other.s;
        return r > other.r;
    }
};

struct desc { // 시작시간 기준 오름차순 pq1용
    int s, r;
    bool operator<(const desc& other) const {
        if (s == other.s) return r > other.r;
        return s > other.s;
    }
};

int solution(vector<vector<int>> jobs) {
    priority_queue<desc> pq1; // 시작시간이 아직 오지 않은 작업을 저장할 pq
    priority_queue<order> pq2; // 시작시간 이상 중 수행시간이 가장 짧은 작업을 저장할 pq
    int n = jobs.size(); // jobs의 길이
    
    int t = 0, ans = 0, cnt = 0; // t = 진행 시간, ans = 정답 변수
    for (int i = 0; i < n; i++) pq1.push({jobs[i][0], jobs[i][1]}); // 시작 시간이 되지 않은 작업을 pq2에 우선 저장
    
    while(cnt < n) { // 무한 루프 생성
        // if (pq1.empty() && pq2.empty()) break;
        while (!pq1.empty() && pq1.top().s <= t) { // 시작할 수 있는 작업을 모두 pq2로 옮긴다.
            pq2.push({pq1.top().s, pq1.top().r});
            pq1.pop();
        }
        if (!pq2.empty()) { // 현재 수행 가능한 작업이 있고, 아직 작업을 처리하지 않았다면
            cnt++;
            t += pq2.top().r; // 작업 소요시간 만큼 시간을 진행시킴
            ans += t - pq2.top().s; // 요청부터 종료까지 걸린 시간을 ans배열에 더해준다.
            pq2.pop();
        } else t = pq1.top().s;
        cout << ans << " " << t << "\n";
    }
    return ans / n; // 작업 소요시간의 평균을 리턴
}