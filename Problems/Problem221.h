//
// Created by LiuZhizheng on 2018/5/14.
//
#include <vector>
#include <iostream>

#ifndef C_LEETCODE_PROBLEM221_H
#define C_LEETCODE_PROBLEM221_H
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int Max = 0;
        if (matrix.size()>0) {
            vector<vector<int>> data(matrix.size(), vector<int>(matrix[0].size(), 0));
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][matrix[0].size() - 1] == '1') {
                    data[i][matrix[0].size() - 1] = 1;
                    Max = 1;
                }
            }
            for (int i = 0; i < matrix[0].size(); i++) {
                if (matrix[matrix.size() - 1][i] == '1') {
                    data[matrix.size() - 1][i] = 1;
                    Max = 1;
                }
            }
            for (int i = matrix.size() - 2; i >= 0; i--) {
                for (int j = matrix[0].size() - 2; j >= 0; j--) {
                    if (matrix[i][j] == '1') {
                        data[i][j] = min(data[i+1][j+1]+1,min(data[i][j+1]+1,data[i+1][j]+1));
                        Max = max(Max,data[i][j]);

                    }
                }
            }
        }
        return Max*Max;
    }
};
void problem221(){
    vector<char> a;
    a.push_back('1');
    a.push_back('1');
    a.push_back('1');
    vector<char> b;
    b.push_back('1');
    b.push_back('1');
    b.push_back('1');
    vector<char> c;
    c.push_back('1');
    c.push_back('1');
    c.push_back('1');
    vector<vector<char>> data;
    data.push_back(a);
    data.push_back(b);
    data.push_back(c);
    Solution solution;
    cout<<solution.maximalSquare(data)<<endl;
}
#endif //C_LEETCODE_PROBLEM221_H
