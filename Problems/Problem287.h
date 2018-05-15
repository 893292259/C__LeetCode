//
// Created by zzliu on 18-5-15.
//
#include <iostream>
#include <vector>
#ifndef C_LEETCODE_PROBLEM287_H
#define C_LEETCODE_PROBLEM287_H
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast!=slow);
        int pt = 0;
        while (pt!=slow){
            slow = nums[slow];
            pt = nums[pt];
        }
        return pt;
    }
};
void problem287(){
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    Solution solution;
    cout<<solution.findDuplicate(nums)<<endl;
}
#endif //C_LEETCODE_PROBLEM287_H
