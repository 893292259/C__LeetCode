//
// Created by LiuZhizheng on 2018/5/14.
//
#include <iostream>
#include <vector>
#include <stack>
#include "../DataStructures/TreeNode.h"
#ifndef C_LEETCODE_PROBLEM234_H
#define C_LEETCODE_PROBLEM234_H
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (root != nullptr){
            stack<TreeNode*> currentLevel;
            stack<TreeNode*> nextLevel;
            currentLevel.push(root);
            bool left_first = true;
            do{
                results.emplace_back(); 
                while(!currentLevel.empty()){
                    TreeNode* current = currentLevel.top(); 
                    currentLevel.pop();
                    results.back().push_back(current->val);
                    if (left_first){
                        if (current->left) nextLevel.push(current->left);
                        if (current->right) nextLevel.push(current->right);
                    }
                    else{
                        if (current->right) nextLevel.push(current->right);
                        if (current->left) nextLevel.push(current->left);         
                    }
                }
                left_first = !left_first;  
                swap(currentLevel,nextLevel);
            }while (!currentLevel.empty());
        }
        return results;

    }
     
};
void problem103(){
    TreeNode* a = new TreeNode(3);
    TreeNode* b = new TreeNode(9);
    TreeNode* c = new TreeNode(20);
    TreeNode* d = new TreeNode(15);
    TreeNode* e = new TreeNode(7);
    a->left = b;
    a->right = c; 
    c->left = d;
    c->right = e; 
    Solution solution;
    auto results = solution.zigzagLevelOrder(a);
    for (auto& result : results){
        for (auto i : result){
            cout<<i;
        }
        cout<<endl;
    }
}
#endif //C_LEETCODE_PROBLEM234_H
