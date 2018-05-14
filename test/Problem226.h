//
// Created by LiuZhizheng on 2018/5/14.
//
#include <iostream>
#include <vector>
#ifndef C_LEETCODE_PROBLEM226_H
#define C_LEETCODE_PROBLEM226_H
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    static TreeNode* invertTree(TreeNode* root) {
        if (root!=NULL) {
            if (root->left != NULL || root->right != NULL) {
                TreeNode *right = root->right;
                TreeNode *left = root->left;
                root->right = left;
                root->left = right;
                invertTree(left);
                invertTree(right);
            }
        }
        return root;
    }
};

int problem226() {
    TreeNode a(6);
    TreeNode b(5);
    TreeNode c(4);
    a.left = &b;
    a.right = &c;
    Solution::invertTree(&a);
    return 0;
}
#endif //C_LEETCODE_PROBLEM226_H
