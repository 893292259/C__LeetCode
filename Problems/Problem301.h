//
// Created by zzliu on 18-5-23.
//

#ifndef C_LEETCODE_PROBLEM301_H
#define C_LEETCODE_PROBLEM301_H
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        vector<char> pos;
        int state;
        s[0] = '1';

        for (int i=0;i<s.length();i++){

        }
    }
};
void problem301(){
    Solution solution;
    string s = "()())()";
    solution.removeInvalidParentheses(s);
}
#endif //C_LEETCODE_PROBLEM301_H
