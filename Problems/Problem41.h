//
// Created by LiuZhizheng on 2018/5/14.
//
#include <iostream>
#include <vector>
#include <stack>
#include "../DataStructures/TreeNode.h"
#ifndef C_LEETCODE_PROBLEM234_H
#define C_LEETCODE_PROBLEM234_H
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int num_negative = 0;
        for (int i =0; i<nums.size();i++){
            if (nums[i]<=0) {
                swap(nums[i],nums[num_negative]);
                num_negative++;
            }
        }
        for (int i= num_negative; i<nums.size();i++){
            if (abs(nums[i]) <= nums.size()-num_negative) nums[abs(nums[i])-1+num_negative] = -abs( nums[abs(nums[i])-1+num_negative] );
        }
        for (int i= num_negative; i<nums.size();i++){
            if (nums[i]>=0) return i-num_negative+1;
        }
        return nums.size()-num_negative+1;
    } 
};
void problem41(){ 
    vector<int> nums = {2,1};
    Solution solution;
    cout<<solution.firstMissingPositive(nums)<<endl;
}
#endif //C_LEETCODE_PROBLEM234_H
