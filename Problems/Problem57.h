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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int state = 0;
        int start = newInterval[0];
        int end = newInterval[1];
        int newStart;
        for (int i=0; i<intervals.size(); i++){
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];
            if (state == 0){
                if (start>currentEnd) {
                    result.push_back(intervals[i]);
                }
                else if (start>=currentStart){
                    if (end<=currentEnd) {
                        result.push_back(intervals[i]);
                        state = 2;
                    }
                    else {
                        newStart = currentStart;
                        state = 1;
                    }
                }
                else{
                    if (end<currentStart){
                        result.push_back({start,end});
                        result.push_back(intervals[i]);
                        state = 2;
                    }
                    else if (end<=currentEnd){
                        result.push_back({start,currentEnd});
                        state = 2;
                    }
                    else{
                        newStart = start;
                        state = 1;
                    }
                }
            }
            else if (state == 1){
                if (end< currentStart){
                    result.push_back({newStart,end});
                    result.push_back(intervals[i]);
                    state = 2;
                }
                else if (end <= currentEnd){
                    result.push_back({newStart,currentEnd});
                    state = 2;
                }
            }
            else if (state == 2){
                result.push_back(intervals[i]);
            }
        }
        if (state == 0){
            result.push_back(newInterval);
        }
        else if (state == 1){
            result.push_back({newStart,end});
        }
        return result;
    }
};

void problem57(){     
    vector<vector<int>> intervals;
    intervals.push_back({1,2});
    intervals.push_back({3,5}); 
    intervals.push_back({6,7});
    intervals.push_back({8,10}); 
    intervals.push_back({12,16}); 
    vector<int> newInterval = {4,8};
    Solution solution;
    auto result = solution.insert(intervals,newInterval);
    for (auto i : result){
        for (auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
#endif //C_LEETCODE_PROBLEM234_H
