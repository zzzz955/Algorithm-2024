#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int SORTnPOP(const vector<int>& array, int s, int e, int idx) {
    vector<int> temp;
    for (int i = s; i <= e; i++) temp.push_back(array[i]);
    sort(temp.begin(), temp.end());
    return temp[idx];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        int result = SORTnPOP(array, commands[i][0] - 1, commands[i][1] - 1, commands[i][2] - 1);
        answer.push_back(result);
    }
    return answer;
}