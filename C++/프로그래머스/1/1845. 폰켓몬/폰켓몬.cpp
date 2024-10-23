#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int length = nums.size();
    unordered_set<int> dic;
    for (int i : nums) dic.insert(i);
    answer = min(length / 2, (int)dic.size());
    
    return answer;
}