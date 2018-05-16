//
// Created by zzliu on 18-5-16.
//

#include <iostream>
#include <vector>
#ifndef C_LEETCODE_PROBLEM240_H
#define C_LEETCODE_PROBLEM240_H


using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i= matrix.size()-1;
        int j= 0;
        while (i>=0&&j<matrix[0].size()){
            if (matrix[i][j]==target){
                return true;
            }
            else if (matrix[i][j]<target){
                j++;
            }
            else{
                i--;
            }
        }
        return false;
    }
};
void problem240(){
    Solution solution;

}

#endif //C_LEETCODE_PROBLEM240_H
