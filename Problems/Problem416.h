//
// Created by zzliu on 18-5-21.
//

#ifndef C_LEETCODE_PROBLEM416_H
#define C_LEETCODE_PROBLEM416_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if (sum%2==1){
            return false;
        }
        else{
            sum /= 2;
            nums.insert(nums.begin(),0);
            vector<vector<bool>> dp(sum+1,vector<bool>(nums.size(),false));
            for (int i=0;i<nums.size();i++){
                dp[0][i] = 1;
            }
            for (int i=1;i<=sum;i++){
                dp[i][0] = 0;
            }
            for (int i=1;i<=sum;i++){
                int j = 1;
                while (j<nums.size()&&nums[j]<=i){
                    if (dp[i][j-1]==true||(i>=nums[j]&&dp[i-nums[j]][j-1]==true)){
                        dp[i][j] = true;
                    }
                    j++;
                }
            }
            return dp[sum][nums.size()-1];
        }
    }
};
void problem416(){
    Solution solution;
    int data[] = {1,5,11,5};
    vector<int> nums(data,data+4);
    cout<<solution.canPartition(nums)<<endl;
}
#endif //C_LEETCODE_PROBLEM416_H
