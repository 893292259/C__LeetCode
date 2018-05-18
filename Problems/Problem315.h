//
// Created by LiuZhizheng on 2018/5/18.
//

#ifndef C_LEETCODE_PROBLEM315_H
#define C_LEETCODE_PROBLEM315_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    struct data{
        int position;
        int value;
        data(int position, int value) : position(position), value(value) {}
    };
    void mergeSort(vector<data>& nums,vector<int>& result,int head,int tail){
        if (head<tail){
            int mid = (head+tail)/2;
             mergeSort(nums,result,head,mid);
             mergeSort(nums,result,mid+1,tail);
             merge(nums,result,head,tail);
        }
    }
    void  merge(vector<data>& nums,vector<int>& result,int head,int tail) {
        vector<data> temp;
        int i = head;
        int j =  (head+tail)/2+1;
        while (i<=(head+tail)/2&&j<=tail) {
            if (nums[i].value > nums[j].value) {
                temp.push_back(nums[j]);
                j++;
            } else {
                temp.push_back(nums[i]);
                result[nums[i].position] += (j - ((head + tail) / 2 + 1));
                i++;
            }
        }
        for (int k=i;k<=(head+tail)/2;k++) {
            temp.push_back(nums[k]);
            result[nums[k].position] += (j - ((head + tail) / 2 + 1));
        };
        for (int k=j;k<=tail;k++) temp.push_back(nums[k]);
        for (int k=head;k<=tail;k++) nums[k] = temp[k-head];
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        vector<data> nums_1;
        for (int i=0;i<nums.size();i++){
            nums_1.push_back(data(i,nums[i]));
        }
        mergeSort(nums_1,result,0,nums_1.size()-1);
        return result;
    }
};
void problem315(){
    Solution solution;
    int data[] ={1,2,0};
    vector<int> nums(data,data+3);
    solution.countSmaller(nums);
}
#endif //C_LEETCODE_PROBLEM315_H
