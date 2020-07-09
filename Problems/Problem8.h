//
// Created by LiuZhizheng on 2018/5/14.
//
#include <iostream>
#include <vector>
#include <stack>
#include "../DataStructures/TreeNode.h"
#ifndef C_LEETCODE_PROBLEM234_H
#define C_LEETCODE_PROBLEM234_H
using namespace std; 
class Solution {
public:
    int myAtoi(string str) {
        if (str == "") return 0;
        int result = 0;
        int t = 0;
        bool neg = false;
        while (str[t]==' ') t++;
        if (t == str.size()) return 0;
        if (('0'<=str[t] && str[t]<='9') || str[t] == '-' || str[t] == '+'){ 
            neg = str[t] == '-'; 
            t += str[t] == '-' || str[t] == '+'; 
            bool overflow = false;
            while (true){
                if (t >= str.size()) break;
                if ('0' > str[t] || str[t] > '9') break;
                if ((result == INT32_MAX/10 &&  str[t]>'7') || (result > INT32_MAX/10)) {
                    overflow  = true;
                    break;
                }
                result = result*10 + (str[t]- '0');
                t++;
            }
            if (overflow && neg) return INT32_MIN;
            if (overflow && !neg) return INT32_MAX;
            if (neg) result = -result; 
        }
        return result;
    }
};
void problem8(){    
    string s = "42";
    Solution solution;
    cout<<solution.myAtoi(s)<<endl;
    
}
#endif //C_LEETCODE_PROBLEM234_H
