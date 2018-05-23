//
// Created by zzliu on 18-5-22.
//

#ifndef C_LEETCODE_PROBLEM581_H
#define C_LEETCODE_PROBLEM581_H
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size()<=1) return 0;
        stack<int> start;
        stack<int> last;
        int i=1;
        start.push(nums[0]);
        while (start.top()<=nums[i]&&i<nums.size()){
            start.push(nums[i]);
            i++;
        }
        while (start.size()>0&&i<nums.size()){
            while (start.size()>0 &&  start.top()>nums[i]){
                start.pop();
            }
            i++;
        }
        if (start.size()==nums.size()) return 0;
        else {
            i = nums.size() - 2;
            last.push(nums[nums.size() - 1]);
            while (last.top() >= nums[i]&&i>=0) {
                last.push(nums[i]);
                i--;
            }
            while (last.size() > 0 && i >= 0) {
                while (last.size() > 0 && last.top() < nums[i]) {
                    last.pop();
                }
                i--;
            }
            return nums.size() - start.size() - last.size();
        }
    }
};
void problem581(){
    int data[] = {-1, -1,-1,-1};
    vector<int> nums(data,data+4);
    Solution solution;
    cout<<solution.findUnsortedSubarray(nums)<<endl;
}
#endif //C_LEETCODE_PROBLEM581_H
