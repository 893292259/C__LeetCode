//
// Created by zzliu on 18-5-22.
//

#ifndef C_LEETCODE_PROBLEM572_H
#define C_LEETCODE_PROBLEM572_H

#include "../DataStructures/TreeNode.h"
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s!=NULL) {
            return checkSame(s, t)||isSubtree(s->left,t)||isSubtree(s->right,t);
        }
        else{
            return checkSame(s, t);
        }
    }
    bool checkSame(TreeNode* s,TreeNode* t){
        if (s==NULL&&t==NULL){
            return true;
        }
        if (s==NULL&&t!=NULL){
            return false;
        }
        if (s!=NULL&&t==NULL){
            return false;
        }
        return s->val==t->val&&checkSame(s->left,t->left)&&checkSame(s->right,t->right);
    }
};
void problem572(){
    TreeNode a(2);
    TreeNode c(2);
    a.left = &c;
    TreeNode b(2);
    Solution solution;
    cout<<solution.isSubtree(&a,&b);
}
#endif //C_LEETCODE_PROBLEM572_H
