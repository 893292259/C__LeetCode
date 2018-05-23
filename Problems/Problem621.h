//
// Created by zzliu on 18-5-23.
//

#ifndef C_LEETCODE_PROBLEM621_H
#define C_LEETCODE_PROBLEM621_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    static bool comp(int &a,int&b){
        return a>b;
    }
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.size()==0)
            return  0;
        unordered_map<int,int> map;
        for (auto &task:tasks){
            map[task-'A']++;
        }
        vector<int> data;
        for (auto &p:map){
         data.push_back(p.second);
        }
        sort(data.begin(),data.end(),comp);
        int i=1;
        while (i<data.size()&&data[i]==data[0]){
            i++;
        }
        return max(i*data[0]+(data[0]-1)*(n-i+1),(int)tasks.size());
    }
};
void problem621(){
    char data[] = {'A','A','A','B','B','B','C','C'};
    vector<char> tasks(data,data+8);
    Solution solution;
    cout<<solution.leastInterval(tasks,3);
}
#endif //C_LEETCODE_PROBLEM621_H
