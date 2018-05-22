//
// Created by zzliu on 18-5-22.
//

#ifndef C_LEETCODE_PROBLEM494_H
#define C_LEETCODE_PROBLEM494_H
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if (sum<S||sum+S&1) return 0;
        else return findEqual(nums,S+sum>>1);
    }
    int findEqual(vector<int>& nums, int S){
        sort(nums.begin(),nums.end());
        int d =1;
        while(nums.size()>0&&nums[0]==0){
            d <<= 1;
            nums.erase(nums.begin());
        }
        nums.insert(nums.begin(),0);
        vector<vector<int>> dp(S+1,vector<int>(nums.size(),0));
        for (int i =0;i<=S;i++){
            dp[i][0] =0;
        }
        for (int i =0;i<nums.size();i++){
            dp[0][i] =1;
        }
        for (int i =1;i<=S;i++){
            for (int j=1;j<nums.size();j++){
                if (nums[j]<=i){
                    dp[i][j] = dp[i][j-1]+dp[i-nums[j]][j-1];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[S][nums.size()-1]*d;
    }
};
void problem494(){
    int data[] = {1,0};
    int S = 1;
    vector<int> nums(data,data+2);
    Solution solution;
    cout<<solution.findTargetSumWays(nums,S);
}
#endif //C_LEETCODE_PROBLEM494_H
