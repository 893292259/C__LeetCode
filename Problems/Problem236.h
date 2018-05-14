//
// Created by LiuZhizheng on 2018/5/14.
//
#include <stack>
#include <iostream>
#ifndef C_LEETCODE_PROBLEM236_H
#define C_LEETCODE_PROBLEM236_H


#include "../DataStructures/TreeNode.h"

using namespace std;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> data;
        while (root!=NULL){
            data.push(root);
            root = root->left;
        }
        TreeNode* target;
        while (data.size()>0){
            TreeNode* current = data.top();
            if (current==p){
                 target = q;
                break;
            }
            else if (current==q){
                target = p;
                break;
            }
            else{
                data.pop();
                if (current->right!=NULL) {
                    current = current->right;
                    while (current != NULL) {
                        data.push(current);
                        current = current->left;
                    }
                }
            }
        }
        TreeNode* parent;
        while (data.size()>0) {
                parent = data.top();
                if (parent!=NULL&&findTarget(parent,target)){
                    break;
                }
                data.pop();

            }
        return parent;
    }


    bool findTarget(TreeNode* parent, TreeNode*target){
        if (parent==target){
            return true;
        }
        else{
            bool result = false;
            if (parent->left!=NULL){
                result|=findTarget(parent->left,target);
            }
            if (parent->right!=NULL){
                result|=findTarget(parent->right,target);
            }
            return result;
        }
    }
};
void problem236(){
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(1);
    TreeNode d(4);
    a.left = &b;

    Solution solution;
    cout<<solution.lowestCommonAncestor(&a,&a,&b)->val<<endl;
}
#endif //C_LEETCODE_PROBLEM236_H
