#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include "../DataStructures/TreeNode.h"
#include <unordered_set>
#ifndef C_LEETCODE_PROBLEM234_H
#define C_LEETCODE_PROBLEM234_H
using namespace std; 

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> potential_pos;
        vector<int> dp(nums.size(),0);
        potential_pos.insert(0);
        for (int i=1;i<nums.size();i++){
            int min = nums.size();
            bool place = true;
            for (auto it = potential_pos.begin(); it!=potential_pos.end();){
                if (nums[*it]+*it >= i + nums[i]) place = false;
                if (nums[*it]+*it < i) potential_pos.erase(it++);
                else {
                    if  (dp[*it] + 1<min) min = dp[*it] + 1;
                    it++;
                }
            }
            dp[i] = min;
            if (place) potential_pos.insert(i);
        }
        return dp[nums.size()-1];
    }
   
};

void problem45(){     
    vector<int> nums = {2,3,1,1,4};
    Solution solution;
    cout<<solution.jump(nums)<<endl;
}
#endif //C_LEETCODE_PROBLEM234_H
