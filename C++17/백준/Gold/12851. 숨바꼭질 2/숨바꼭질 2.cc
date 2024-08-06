#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100000;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> visited(MAX + 1, -1);  // 최단 시간 저장, 초기화는 -1로
    vector<int> ways(MAX + 1, 0);      // 경로의 수 저장

    queue<int> q;
    q.push(N);
    visited[N] = 0;  // 수빈이의 시작 위치
    ways[N] = 1;     // 시작 위치에서 동생을 찾는 방법은 하나

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        int next_positions[3] = { current - 1, current + 1, current * 2 };

        for (int i = 0; i < 3; ++i) {
            int next = next_positions[i];

            if (next < 0 || next > MAX) continue;  // 범위를 벗어난 경우 무시

            if (visited[next] == -1) {  // 처음 방문하는 경우
                visited[next] = visited[current] + 1;
                ways[next] = ways[current];
                q.push(next);
            }
            else if (visited[next] == visited[current] + 1) {  // 같은 시간에 도달한 경우
                ways[next] += ways[current];
            }
        }
    }

    cout << visited[K] << '\n';  // 동생을 찾는 최단 시간
    cout << ways[K] << '\n';     // 그 방법의 수

    return 0;
}
