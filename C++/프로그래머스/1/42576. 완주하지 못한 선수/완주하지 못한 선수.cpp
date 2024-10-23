#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer;
    
    unordered_map<string, int> dic;
    for (const string& s : completion) dic[s]++;
    for (const string& s : participant) {
        if (!dic[s]) {
            answer = s;
            break;
        }
        else dic[s]--;
    }
    
    return answer;
}