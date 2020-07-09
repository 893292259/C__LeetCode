//
// Created by LiuZhizheng on 2018/5/14.
//
#include <iostream>
#include <vector>
#include <stack>
#include "../DataStructures/TreeNode.h"
#ifndef C_LEETCODE_PROBLEM44_H
#define C_LEETCODE_PROBLEM44_H
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) { 
        vector<vector<bool>> matching(p.size()+1,vector<bool>(s.size()+1,false));
        matching[0][0] = true;
        
        for (int i = 1; i<p.size()+1;i++){
            for (int j = 0; j<s.size()+1; j ++){
                if(p[i-1] == '*') {
                    for (int k=j; k>=0;k--){
                        if (matching [i-1][k]){
                            matching[i][j] = true;
                            break;
                        }
                    } 
                }
                else if(p[i-1] == '?') {
                    if (j == 0) matching[i][j] = false;
                    else matching[i][j] = matching[i-1][j-1];
                }
                else{
                    if (j ==0) matching[i][j] = false;
                    else matching[i][j] = matching[i-1][j-1] && p[i-1] == s[j-1];
                }
            }
        }
        return matching[p.size()][s.size()];

    }
};
void problem44(){ 
    string s = "aa";
    string p = "a";
    Solution solution;
    cout<<solution.isMatch(s,p)<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
}
#endif //C_LEETCODE_PROBLEM234_H
