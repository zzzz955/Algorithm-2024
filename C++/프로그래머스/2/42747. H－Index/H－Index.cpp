#include <string>
#include <vector>

using namespace std;

int v[10001];

int solution(vector<int> citations) {
    for (int i:citations) while(i) v[i--]++;
    int len = citations.size();
    
    int h_index = 0;
    while(len) {
        if (v[len] >= len) {
            h_index = len;
            break;
        }
        else len--;
    }
    
    return h_index;
}