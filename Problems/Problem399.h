//
// Created by LiuZhizheng on 2018/5/14.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
#include <stack>
#include "../DataStructures/TreeNode.h"
#ifndef C_LEETCODE_PROBLEM234_H
#define C_LEETCODE_PROBLEM234_H
using namespace std;
class Solution {
public:    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,map<string, double>> dict;
        for (int i=0; i< values.size(); i++){
            string first = equations[i][0];
            string second = equations[i][1];
            if (dict.find(first) == dict.end()) dict[first][first] = 1.0;
            if (dict.find(second) == dict.end()) dict[second][second] = 1.0;
            if (dict[first].find(second) == dict[first].end()){
                for (auto &o : dict[first]){
                    for (auto &p :dict[second]){
                        dict[o.first][p.first] = 1/o.second * values[i]*p.second;
                        dict[p.first][o.first] = o.second / values[i]/p.second;
                    }
                }  
            }
        }
        vector<double> results;
        for (int i=0; i<queries.size();i++){
            string first = queries[i][0];
            string second = queries[i][1]; 
            if (dict[first].find(second) == dict[first].end()) results.push_back(-1.0);
            else results.push_back(dict[first][second]);
        }
        return results;
    }
};
void problem399(){ 
     
}
#endif //C_LEETCODE_PROBLEM234_H
