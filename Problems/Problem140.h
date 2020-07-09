//
// Created by LiuZhizheng on 2018/5/14.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include "../DataStructures/TreeNode.h"
#ifndef C_LEETCODE_PROBLEM234_H
#define C_LEETCODE_PROBLEM234_H
using namespace std;
class Solution {
public:
    void dfs(vector<string> &result, string &s, vector<vector<int>> &dp, string t, int n){
        for (auto o :dp[n]){
            if (o==n){ 
                result.push_back(s.substr(0,n) + t);
            }
            else dfs(result,s,dp," "+s.substr(n-o,o)+t,n-o);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for (auto& word : wordDict){
            wordSet.insert(word);
        }
        vector<vector<int>> dp(s.size()+1);
        for (int i=1; i<s.size()+1;i++){
            for (int j=0; j<i; j++){
                string ss = s.substr(j,i-j);
                if (wordSet.find(ss)!=wordSet.end() && (dp[j].size()>0 || j==0)){
                            dp[i].push_back(i-j);
                }
            }
        }
        vector<string> result;
        dfs (result,s,dp,"",s.size());
        return result;

    }
     
};
void problem140(){
  Solution solution;
  string s = "pineapplepenapple";
  vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
  vector<string> result =solution.wordBreak(s,wordDict);
  for (auto&s : result){
      cout<<s<<endl;
  }
}
#endif //C_LEETCODE_PROBLEM234_H
