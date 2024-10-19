#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for (int i:arr) {
        if (!answer.empty() && answer.back() == i) continue;
        answer.push_back(i);
    }

    return answer;
}