//
// Created by LiuZhizheng on 2018/5/14.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <stack>
#include "../DataStructures/TreeNode.h"
#ifndef C_LEETCODE_PROBLEM234_H
#define C_LEETCODE_PROBLEM234_H
using namespace std;
class Solution {
public:
    int gcd(int a,int b) {
        while(b^=a^=b^=a%=b);
        return a;
    }
    int maxPoints(vector<vector<int>>& points) {  
        int result = 0;
        unordered_set<int> skip;
        for (int i=0; i<points.size(); i++){
            if (result >= points.size()-i) break;
            if (skip.find(i) != skip.end()) continue;
            map<pair<int,int>,int> dict;
            int same_points = 0;
            for (int j=i+1; j<points.size();j++){
                pair<int,int> key;
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    same_points++;
                    skip.insert(j);
                    continue;
                }
                else if (points[i][0] == points[j][0]){
                    key = make_pair(0,1);
                }
                else if (points[i][1] == points[j][1]){
                    key = make_pair(1,0);
                }
                else{
                    int gg = gcd(points[i][0]-points[j][0], points[i][1]-points[j][1]);
                    if ((points[i][0]-points[j][0])/gg<0) gg = -gg;
                    key = make_pair((points[i][0]-points[j][0])/gg, (points[i][1]-points[j][1])/gg);
                }
                dict[key]++;
            }
            if (same_points + 1 > result) result = same_points + 1;
            for (auto &o : dict){
                if(o.second+same_points + 1 > result) result = o.second+same_points + 1;
            }
        }
        return result;

    }
};
void problem149(){ 
    vector<vector<int>> points;
    Solution solution;
    vector<int> p1 = {1,1};
    points.push_back(p1);
    vector<int> p2 = {3,2};
    points.push_back(p2);
    vector<int> p3 = {5,3};
    points.push_back(p3);
    vector<int> p4 = {4,1};
    points.push_back(p4);
    vector<int> p5 = {2,3};
    points.push_back(p5);
    vector<int> p6 = {1,4};
    points.push_back(p6);
    cout<<solution.maxPoints(points)<<endl;
    cout<<endl;
}
#endif //C_LEETCODE_PROBLEM234_H
