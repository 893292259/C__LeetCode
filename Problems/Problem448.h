//
// Created by zzliu on 18-5-21.
//

#ifndef C_LEETCODE_PROBLEM448_H
#define C_LEETCODE_PROBLEM448_H
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            while (val!=0){
                int next = nums[val-1];
                nums[val-1] = 0;
                val = next;
            }
        }
        for (int i=0;i<nums.size();i++){
            if (nums[i]>0){
                result.push_back(i+1);
            }
        }
        return result;
    }
};
void problem448(){
   Solution solution;
   int data[] = {4,3,2,7,8,2,3,1};
   vector<int> nums(data,data+8);
   solution.findDisappearedNumbers(nums);
}
#endif //C_LEETCODE_PROBLEM448_H
