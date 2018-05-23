//
// Created by zzliu on 18-5-23.
//

#ifndef C_LEETCODE_PROBLEM617_H
#define C_LEETCODE_PROBLEM617_H
#include <iostream>
#include <vector>
#include <stack>
#include "../DataStructures/TreeNode.h"

using namespace std;
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t2 == NULL){
            return t1;
        }
        if (t1 == NULL){
            return t2;
        }
        t1->val = t2->val+t1->val;
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        return t1;
    }
};
void problem617(){
    Solution solution;
    TreeNode a(5);
    TreeNode b(3);
    TreeNode c(2);
    TreeNode d(1);
    a.left = &b;
    c.right = &d;
    solution.mergeTrees(&a,&c);
}
#endif //C_LEETCODE_PROBLEM617_H
