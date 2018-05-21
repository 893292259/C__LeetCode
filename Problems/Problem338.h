//
// Created by zzliu on 18-5-18.
//

#ifndef C_LEETCODE_PROBLEM338_H
#define C_LEETCODE_PROBLEM338_H
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        result.push_back(0);
        if (num>0) {
            result.push_back(1);
            int j = 2;
            for (int i = 2; i <= num; i++) {
                if (i >= 2 * j) j *= 2;
                result.push_back(result[i - j] + 1);
            }
        }
        return result;
    }
};
void problem338(){
    Solution solution;
    solution.countBits(5);
};
#endif //C_LEETCODE_PROBLEM338_H
