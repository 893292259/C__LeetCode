//
// Created by zzliu on 18-5-22.
//

#ifndef C_LEETCODE_PROBLEM538_H
#define C_LEETCODE_PROBLEM538_H
#include <iostream>
#include "../DataStructures/TreeNode.h"
#include <stack>
using namespace std;
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* current = root;
        int sum = 0;
        stack<TreeNode*> data;
        while (current!=NULL){
            data.push(current);
            current = current->right;
        }
        while (data.size()>0){
            TreeNode* now = data.top();
            now->val += sum;
            sum = now->val;
            data.pop();
            now = now->left;
            while (now!=NULL){
                    data.push(now);
                    now = now->right;
            }
        }
        return root;
    }
};
void problem538() {
    Solution solution;
    TreeNode a(5);
    TreeNode b(2);
    TreeNode c(13);
    a.right = &c;
    a.left = &b;
    solution.convertBST(&a);
};
#endif //C_LEETCODE_PROBLEM538_H
