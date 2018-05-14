//
// Created by LiuZhizheng on 2018/5/14.
//
#include <iostream>
#ifndef C_LEETCODE_TREENODE_H
#define C_LEETCODE_TREENODE_H
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif //C_LEETCODE_TREENODE_H
