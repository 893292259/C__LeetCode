//
// Created by zzliu on 18-5-16.
//
#include <iostream>
#include <vector>
#ifndef C_LEETCODE_PROBLEM279_H
#define C_LEETCODE_PROBLEM279_H

using namespace std;
class Solution {
public:
    int numSquares(int n) {
       vector<int> dp;
       dp.push_back(0);
       for (int i=1;i<=n;i++){
           int j=1;
           int Min = i;
           while (j*j<=i){
               Min = min(Min,1+dp[i-j*j]);
               j++;
           }
           dp.push_back(Min);
       }
        return dp[n];
    }
};
void problem279(){
    Solution solution;
    cout<<solution.numSquares(12)<<endl;
}
#endif //C_LEETCODE_PROBLEM279_H
