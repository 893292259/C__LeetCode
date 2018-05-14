//
// Created by LiuZhizheng on 2018/5/14.
//
#include <iostream>
#include <vector>

#ifndef C_LEETCODE_PROBLEM238_H
#define C_LEETCODE_PROBLEM238_H
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(),1);
        for (int i=1;i<nums.size();i++){
            result[i] = result[i-1]*nums[i-1];
        }
        int temp=1;
        for (int i=nums.size()-1;i>=0;i--){
            result[i] *= temp;
            temp *= nums[i];
        }
        return result;
    }
};
void problem238() {
    vector<int> data;
    Solution solution;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    data.push_back(4);
    solution.productExceptSelf(data);
}
#endif //C_LEETCODE_PROBLEM238_H
