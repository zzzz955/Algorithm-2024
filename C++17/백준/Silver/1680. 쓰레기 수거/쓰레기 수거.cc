#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T; // 테스트 케이스 수
    cin >> T;

    while (T--) {
        int W, N; // 쓰레기차의 용량 W, 지점의 개수 N
        cin >> W >> N;

        vector<pair<int, int>> locations(N); // 각 지점의 거리와 쓰레기 양을 저장할 벡터

        for (int i = 0; i < N; ++i) {
            cin >> locations[i].first >> locations[i].second; // 거리 x_i, 쓰레기 양 w_i
        }

        int total_distance = 0; // 총 이동 거리
        int current_capacity = 0; // 현재 쓰레기차에 적재된 쓰레기 양

        // 모든 지점을 순회
        for (int i = 0; i < N; ++i) {
            int distance = locations[i].first; // 현재 지점의 거리
            int trash = locations[i].second; // 현재 지점에서 수거해야 할 쓰레기 양

            // 현재 지점의 쓰레기를 모두 수거할 수 없다면
            if (current_capacity + trash > W) {
                // 현재 용량을 넘기 전에 쓰레기장으로 돌아가서 쓰레기를 비워야 함
                total_distance += 2 * distance; // 왕복 거리 추가
                current_capacity = 0; // 쓰레기차를 비움
            }

            // 현재 지점의 쓰레기를 모두 수거
            current_capacity += trash;

            // 쓰레기차의 용량이 꽉 찼다면 즉시 돌아가서 쓰레기를 비움
            if (current_capacity == W) {
                total_distance += 2 * distance; // 왕복 거리 추가
                current_capacity = 0; // 쓰레기차를 비움
            }
        }

        // 모든 지점에서 쓰레기를 수거했을 때 남은 쓰레기가 있으면 마지막으로 한 번 더 왕복
        if (current_capacity > 0) {
            total_distance += 2 * locations[N - 1].first; // 마지막 지점까지의 왕복 거리
        }

        cout << total_distance << endl; // 결과 출력
    }

    return 0;
}
