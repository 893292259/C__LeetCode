//
// Created by zzliu on 18-5-16.
//
#include <iostream>
#include <vector>
#ifndef C_LEETCODE_PROBLEM218_H
#define C_LEETCODE_PROBLEM218_H
using namespace std;

class Solution {
public:
    int findPosition1 (int currentLeft,int head, int tail, vector<pair<int,int>>& stack){
        if (head==tail){
            return head;
        }
        else{
            int mid = (head+tail)/2;
            if (stack[mid].first<=currentLeft){
                return findPosition1(currentLeft,mid+1,tail,stack);
            }
            else{
                return findPosition1(currentLeft,head,mid,stack);
            }
        }

    }
    int findPosition2 (int currentHeight,int head, int tail, vector<pair<int,int>>& stack){
        if (head==tail){
            return head;
        }
        else{
            int mid = (head+tail)/2;
            if (stack[mid].second>=currentHeight){
                return findPosition2(currentHeight,mid+1,tail,stack);
            }
            else{
                return findPosition2(currentHeight,head,mid,stack);
            }
        }

    }

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> stack;
        vector<pair<int ,int>> result;
        if (buildings.size()>0) {
            pair<int, int> init1(buildings[0][0], buildings[0][2]);
            stack.push_back(init1);
            pair<int, int> init2(buildings[0][1], 0);
            stack.push_back(init2);
            for (int i = 1; i < buildings.size(); i++) {
                int leftPlace = findPosition1(buildings[i][0], 0, stack.size(), stack) - 1;
                if (stack[leftPlace].second <= buildings[i][2]) {
                    int lastHeight = stack[leftPlace].second;
                    for (int i = 0; i <= leftPlace; i++) {
                        result.push_back(stack[i]);
                    }
                    stack.erase(stack.begin(), stack.begin() + leftPlace + 1);
                    pair<int, int> result1(buildings[i][0], buildings[i][2]);
                    stack.insert(stack.begin(), result1);
                    int rightPlace = findPosition1(buildings[i][1], 0, stack.size(), stack) - 1;
                    pair<int, int> result2;
                    if (rightPlace > 0) {
                        result2.first = buildings[i][1];
                        result2.second = stack[rightPlace].second;
                    } else {
                        result2.first = buildings[i][1];
                        result2.second = lastHeight;
                    }
                    stack.insert(stack.begin() + rightPlace + 1, result2);
                    stack.erase(stack.begin() + 1, stack.begin() + rightPlace + 1);
                } else {
                    int rightPlace = findPosition1(buildings[i][1], 0, stack.size(), stack) - 1;
                    int heightPlace = findPosition2(buildings[i][2], 0, stack.size(), stack) - 1;
                    if (heightPlace < rightPlace) {
                        pair<int, int> result1(stack[heightPlace + 1].first, buildings[i][2]);
                        pair<int, int> result2(buildings[i][1], stack[rightPlace].second);
                        stack.insert(stack.begin() + heightPlace + 1, result1);
                        stack.insert(stack.begin() + rightPlace + 2, result2);
                        stack.erase(stack.begin() + heightPlace + 2, stack.begin() + rightPlace + 2);
                    }
                }
            }
            for (int i = 0; i < stack.size(); i++) {
                result.push_back(stack[i]);
            }

            int i = result.size() - 2;
            while (i >= 0) {
                if (result[i].first == result[i + 1].first) {
                    result.erase(result.begin() + i, result.begin() + i + 1);
                }
                i--;
            }
            i = 1;
            while (i != result.size()) {
                if (result[i].second == result[i - 1].second) {
                    result.erase(result.begin() + i, result.begin() + i + 1);
                } else {
                    i++;
                }
            }
        }
        return result;
    }
};
void problem218(){
    Solution solution;
    int a1[] = {0,2,3};
    vector<int>  b1(a1,a1+3);
    int a2[] = {2,5,3};
    vector<int>  b2(a2,a2+3);
    //int a3[] = {5,12,12};
    //vector<int>  b3(a3,a3+3);
    //int a4[] = {15,20,10};
    //vector<int>  b4(a4,a4+3);
    //int a5[] = {19,24,8};
    //vector<int>  b5(a5,a5+3);
    vector<vector<int>> buildings;
    buildings.push_back(b1);
    buildings.push_back(b2);
    //buildings.push_back(b3);
    //buildings.push_back(b4);
    //buildings.push_back(b5);
    solution.getSkyline(buildings);
}
#endif //C_LEETCODE_PROBLEM218_H
