//
// Created by zzliu on 18-5-17.
//

#ifndef C_LEETCODE_PROBLEM312_H
#define C_LEETCODE_PROBLEM312_H
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.begin()+nums.size(),1);
        return helper(nums);
    }
    int helper(vector<int>& nums){
        vector<vector<int>> dp (nums.size(),vector<int>(nums.size(),0));
        for (int i=2;i<=nums.size()-1;i++){
            for (int j=0;j+i<=nums.size()-1;j++){
                int Max = 0;
                for (int k=j+1;k<j+i;k++){
                    Max = max(Max,nums[j]*nums[i+j]*nums[k]+dp[j][k]+dp[k][i+j]);
                }
                dp[j][i+j] = Max;
            }
        }
        return dp[0][nums.size()-1];
    }
};
void problem312(){
 int data[]={3, 1, 5, 8};
 vector<int> nums(data,data+4);
 Solution solution;
 cout<<solution.maxCoins(nums)<<endl;
}
#endif //C_LEETCODE_PROBLEM312_H
