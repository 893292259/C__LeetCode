//
// Created by zzliu on 18-5-22.
//

#ifndef C_LEETCODE_PROBLEM560_H
#define C_LEETCODE_PROBLEM560_H

#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int Max = 1;
        nums.insert(nums.begin(),0);
        for (int i=1;i<nums.size();i++){
            Max = max(Max,abs(nums[i]));
            nums[i] += nums[i-1];
        }
        int sum = 0;
        for (int i=0;i<nums.size();i++){
            int j = i+1;
            while (j<nums.size()){
                int diff = nums[j]-nums[i];
                if (diff==k){
                    sum++;
                    j++;
                }
                else{
                    j += (abs(diff-k)-1)/Max+1;
                }
            }
        }
        return sum;
    }
};
void problem560(){
    int data[] = {1,1,1};
    vector<int> nums(data,data+3);
    Solution solution;
    cout<<solution.subarraySum(nums,2)<<endl;
}
#endif //C_LEETCODE_PROBLEM560_H
