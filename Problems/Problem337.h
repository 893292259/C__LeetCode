//
// Created by zzliu on 18-5-18.
//

#ifndef C_LEETCODE_PROBLEM337_H
#define C_LEETCODE_PROBLEM337_H

#include "../DataStructures/TreeNode.h"
#include <iostream>
using namespace std;
class Solution {
public:
    int rob(TreeNode* root) {
        if (root!=NULL) {
            if (root->val>=0) {
                int Max = max(rob(root->right) + rob(root->left), skip(root->left) + skip(root->right) + root->val);
                root->val = -Max;
            }
                return -root->val;
            }
        else{
            return  0;
        }
    }
    int skip(TreeNode* root){
        if (root!=NULL){
            return rob(root->left)+rob(root->right);
        }
        else{
            return  0;
        }
    }
};
void problem337(){
    TreeNode a(3);
    TreeNode b(4);
    TreeNode c(5);
    a.left = &b;
    a.right = &c;
    Solution solution;
    cout<<solution.rob(&a)<<endl;
}
#endif //C_LEETCODE_PROBLEM337_H
