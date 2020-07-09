//
// Created by LiuZhizheng on 2018/5/14.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#ifndef C_LEETCODE_PROBLEM238_H
#define C_LEETCODE_PROBLEM238_H
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int>> s; 
        vector<int> result(T.size(),0); 
        for (int i =0; i<T.size(); i++){
            while (!s.empty()&&s.top().first<T[i]){
                result[s.top().second] = i-s.top().second;
                s.pop();
            }
            s.push(make_pair(T[i],i));
        }
    return result;
    }
};
void problem739() { 
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution solution; 
    solution.dailyTemperatures(T);
}
#endif //C_LEETCODE_PROBLEM238_H