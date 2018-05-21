//
// Created by zzliu on 18-5-21.
//

#ifndef C_LEETCODE_PROBLEM437_H
#define C_LEETCODE_PROBLEM437_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "../DataStructures/TreeNode.h"
using namespace std;
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root==NULL) return 0;
        else{
            int result1 = root->val==sum;
            int result2 = onlyPathSum(root->right,sum-root->val)+pathSum(root->right,sum);
            int result3 = onlyPathSum(root->left,sum-root->val)+pathSum(root->left,sum);
            return result1+result2+result3;
        }
    }
    int onlyPathSum(TreeNode* root, int sum) {
        if (root==NULL) return 0;
        else{
            int result1 = root->val==sum;
            int result2 = onlyPathSum(root->right,sum-root->val);
            int result3 = onlyPathSum(root->left,sum-root->val);
            return result1+result2+result3;
        }
    }
};
void problem437(){
    Solution solution;
    TreeNode a(5);
    TreeNode b(0);
    TreeNode c(0);
    TreeNode d(0);
    a.right = &b;
    a.left = &c;
    c.right = &d;
    cout<<solution.pathSum(&c,0)<<endl;
}

#endif //C_LEETCODE_PROBLEM437_H
