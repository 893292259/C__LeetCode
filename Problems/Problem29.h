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
   int divide_help(int dividend, int divisor){
        int bit = 0; 
        while (((divisor<<bit)>0) && ((dividend - (divisor<<bit))>=0) ) bit++;
        if (bit == 0) return 0;
        else return (1<<(bit-1)) + divide_help(dividend - (divisor<<(bit-1)),divisor);
    }
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (dividend == INT32_MIN &&  divisor == 1) return dividend;
        if (dividend == INT32_MIN &&  divisor == -1) return INT32_MAX;

        bool oneplus = false;
        if (dividend == INT32_MIN){
            dividend = dividend + abs(divisor);
            oneplus = true;
        }
 
        int result = divide_help(abs(dividend),abs(divisor)) + oneplus; 
        if ((dividend >0 && divisor<0) || (dividend <0 && divisor>0)) result = -result;
        return result;
    }
};
void problem29(){    
    int a =INT32_MAX;
    int b = 1;
    Solution solution; 
    cout<<solution.divide(a,b)<<endl;
}
#endif //C_LEETCODE_PROBLEM234_H
