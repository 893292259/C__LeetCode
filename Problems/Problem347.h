//
// Created by zzliu on 18-5-23.
//

#ifndef C_LEETCODE_PROBLEM347_H
#define C_LEETCODE_PROBLEM347_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    struct record{
        int num;
        int freequency;
        record(int num, int freequency) : num(num), freequency(freequency) {}
    };
    static bool comp(record& a, record& b){
        return a.freequency>=b.freequency;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> map;
        for (auto& num:nums){
            map[num]++;
        }
        vector<record> data;
        for (auto& p:map){
            data.push_back(record(p.first,p.second));
        }
        target(data,0,data.size()-1,k-1);
        sort(data.begin(),data.begin()+k,comp);
        for (int i=0;i<k;i++){
            result.push_back(data[i].num);
        }
        return result;
    }
    void target(vector<record>& data,int head,int tail,int num){
        record q = data[head];
        int i=head;
        int j=tail;
        while (i<j){
            if (data[i+1].freequency>=q.freequency){
                data[i] = data[i+1];
                i++;
            }
            else{
                record temp = data[j];
                data[j] = data[i+1];
                data[i+1] = temp;
                j--;
            }
        }
        data[i] = q;
        if (i<num){
            target(data,i+1,tail,num);
        }
        if (i>num+1){
            target(data,head,i-1,num);
        }
    }
};
void problem347(){
    int data[] = {3,1,0,0};
    vector<int> nums(data,data+4);
    Solution solution;
    solution.topKFrequent(nums,1);
}
#endif //C_LEETCODE_PROBLEM347_H
