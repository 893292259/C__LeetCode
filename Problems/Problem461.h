//
// Created by zzliu on 18-5-22.
//

#ifndef C_LEETCODE_PROBLEM461_H
#define C_LEETCODE_PROBLEM461_H
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        while (x!=0||y!=0){
            result += (x%2!=y%2);
            x /= 2;
            y /= 2;
        }
        return result;
    }
};
void problem461(){
    int x = 4;
    int y =1;
    Solution solution;
    cout<<solution.hammingDistance(x,y)<<endl;
}
#endif //C_LEETCODE_PROBLEM461_H
