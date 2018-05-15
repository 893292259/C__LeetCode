//
// Created by zzliu on 18-5-15.
//
#include <iostream>
#include <vector>
#ifndef C_LEETCODE_PROBLEM300_H
#define C_LEETCODE_PROBLEM300_H

using namespace std;
class Solution {
public:
    int searchPlace(int target, int head, int tail, vector<int>& dp){
        if (head==tail){
            return head;
        }
        else{
            int mid = (head+tail)/2;
            if (dp[mid]<target){
                return  searchPlace(target,mid+1,tail,dp);
            }
            else{
                return  searchPlace(target,head,mid,dp);
            }
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        if (nums.size()>0) {
            dp.push_back(nums[0]);
            for (int i = 1; i < nums.size(); i++) {
                int place = searchPlace(nums[i], 0, dp.size(), dp);
                if (place == dp.size()) {
                    dp.push_back(nums[i]);
                } else {
                    dp[place] = nums[i];
                }
            }
        }
        return dp.size();
    }
};
void problem300(){
    Solution solution;
    int data[]={10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums(data,data+8);
    cout<<solution.lengthOfLIS(nums);
}
#endif //C_LEETCODE_PROBLEM300_H
