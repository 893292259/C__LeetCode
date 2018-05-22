//
// Created by zzliu on 18-5-22.
//

#ifndef C_LEETCODE_PROBLEM543_H
#define C_LEETCODE_PROBLEM543_H

#include "../DataStructures/TreeNode.h"
#include <iostream>
using namespace std;
class Solution {
public:
    int Max;
    int diameterOfBinaryTree(TreeNode* root) {
        Max = 0;
        if (root!=NULL) {
            int a = findMax(root->left);
            int b = findMax(root->right);
            Max = max(Max, a + b);
        }
        return Max;

    }
    int findMax(TreeNode* root){
        if (root==NULL){
            return 0;
        }
        else{
            int a= findMax(root->left);
            int b= findMax(root->right);
            Max = max(Max,a+b);
            return max(a,b)+1;
        }
    }
};
void problem543(){
    TreeNode a(5);
    TreeNode b(5);
    TreeNode c(5);
    TreeNode d(5);
    TreeNode e(5);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    Solution solution;
    cout<<solution.diameterOfBinaryTree(&a)<<'\n';
}
#endif //C_LEETCODE_PROBLEM543_H
