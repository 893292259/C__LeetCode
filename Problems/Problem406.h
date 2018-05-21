//
// Created by zzliu on 18-5-21.
//

#ifndef C_LEETCODE_PROBLEM406_H
#define C_LEETCODE_PROBLEM406_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int,int>> result;
        if (people.size()>0){
        sort(people.begin(),people.end(),comp);
        for (int i=0;i<people.size();i++){
            result.insert(result.begin()+people[i].second,people[i]);
        }
        }
        return result;
    }
    static bool comp(pair<int,int>& a,pair<int,int>& b){
        return a.first>b.first||(a.first==b.first&&a.second<b.second);
    }

};

void problem406(){
    Solution solution;
    pair<int,int> p1 = {7,0};
    pair<int,int> p2 = {4,4};
    pair<int,int> p3 = {7,1};
    pair<int,int> p4 = {5,0};
    pair<int,int> p5 = {6,1};
    pair<int,int> p6 = {5,2};
    vector<pair<int,int>> people;
    people.push_back(p1);
    people.push_back(p2);
    people.push_back(p3);
    people.push_back(p4);
    people.push_back(p5);
    people.push_back(p6);
    solution.reconstructQueue(people);

}
#endif //C_LEETCODE_PROBLEM406_H
