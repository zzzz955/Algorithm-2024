#include <string>
#include <vector>

using namespace std;

int total;
vector<int> answer;

vector<int> solution(int brown, int yellow) {
    total = brown + yellow;
    
    for (int h = 3; h <= total / h; h++) {
        if (total % h) continue;
        int w = total / h;
        if (w * 2 + h * 2 - 4 + yellow == total) {
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }
    
    return answer;
}