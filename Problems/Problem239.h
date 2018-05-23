//
// Created by zzliu on 18-5-23.
//

#ifndef C_LEETCODE_PROBLEM239_H
#define C_LEETCODE_PROBLEM239_H
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:

    int findPosition (int target,int head, int tail, vector<int>& stack) {
        if (head == tail) {
            return head;
        } else {
            int mid = (head + tail) / 2;
            if (stack[mid] > target) {
                return findPosition(target, mid+1, tail, stack);
            } else {
                return findPosition(target, head, mid, stack);
            }
        }
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> currentMax;
        vector<int> result;
        if (nums.size()==0) return result;
        currentMax.push_back(nums[k-1]);
        for (int i=k-2;i>=0;i--) {
            if (nums[i]>currentMax[0]){
                currentMax.insert(currentMax.begin(),nums[i]);
            }
            else{
                currentMax.insert(currentMax.begin(),currentMax[0]);
            }
        }
        result.push_back(currentMax[0]);
        for (int i=k;i<nums.size();i++){
            currentMax.erase(currentMax.begin());
            int place = findPosition(nums[i],0,currentMax.size(),currentMax);
            currentMax.erase(currentMax.begin()+place,currentMax.end());
            vector<int> temp(k-currentMax.size(),nums[i]);
            currentMax.insert(currentMax.end(),temp.begin(),temp.end());
            result.push_back(currentMax[0]);
        }
        return result;
    }
};
void problem239(){
    Solution solution;
    int data[] = {1,3,-1,-3,5,3,6,7};
    vector<int> nums(data,data+8);
    solution.maxSlidingWindow(nums,3);
}
#endif //C_LEETCODE_PROBLEM239_H
