#include <string>
#include <vector>

using namespace std;

int s[32];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for (int i = 1; i <= n; i++) s[i] = 1;
    for (int i : lost) s[i]--;
    for (int i : reserve) s[i]++;
    for (int i = 1; i <= n; i++) {
        if (s[i]) answer++;
        if (!s[i]) {
            if (s[i - 1] == 2) {
                s[i - 1]--;
                s[i]++;
                answer++;
            }
            else if (s[i + 1] == 2) {
                s[i + 1]--;
                s[i]++;
                answer++;
            }
        }
    }
    
    return answer;
}