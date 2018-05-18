//
// Created by LiuZhizheng on 2018/5/18.
//

#ifndef C_LEETCODE_PROBLEM322_H
#define C_LEETCODE_PROBLEM322_H
#include <iostream>
#include <climits>
#include<algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        sort(coins.begin(),coins.end());
        dp[0] = 0;
        for (int i=1;i<=amount;i++){
            int Min = amount+1;
            int j=0;
            while(j<coins.size()&&coins[j]<=i&&dp[i-coins[j]]!=-1){
                Min = min(Min,1+dp[i-coins[j]]);
                j++;
            }
            if (Min<=amount) dp[i] = Min;
        }
        return dp[amount];
    }
};
void problem322(){
    Solution solution;
    int amount = 12;
    int data[] = {5,7};
    vector<int> coins(data,data+2);
    cout<<solution.coinChange(coins,amount)<<endl;
}
#endif //C_LEETCODE_PROBLEM322_H
