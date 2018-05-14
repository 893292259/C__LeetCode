//
// Created by LiuZhizheng on 2018/5/14.
//
#include <iostream>
#include <vector>
#ifndef C_LEETCODE_PROBLEM283_H
#define C_LEETCODE_PROBLEM283_H

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int probe = 0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]!=0) {
                nums[probe] = nums[i];
                if (probe++<i) {
                    nums[i] = 0;
                }
            }
        }
    }
};
void problem283(){
    Solution solution;
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(12);
    solution.moveZeroes(nums);
}

#endif //C_LEETCODE_PROBLEM283_H
