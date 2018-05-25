//
// Created by zzliu on 18-5-25.
//

#ifndef C_LEETCODE_PROBLEM297_H
#define C_LEETCODE_PROBLEM297_H

#include "../DataStructures/TreeNode.h"
#include <iostream>
#include <stack>

using namespace std;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root==NULL){
            string s= "";
            return s;
        }
        return dfs(root);
    }
    string dfs(TreeNode* root){
        string s = "";
        string num = "";
        int value = root->val;
        if (value<0){
            num = num+"-";
            value = -value;
        }
        do{
            num = (char)(value%10+'0')+num;
            value /= 10;
        }while(value>0);
        s += num;
        if (root->left!=NULL){
            s += "l";
            s += dfs(root->left);
            s += "#";
        }
        if (root->right!=NULL){
            s += "r";
            s += dfs(root->right);
            s += "#";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data=="") return NULL;
        else{
            stack<TreeNode*> nodeStack;
            int num = 0;
            int i=0;
            while ('0'<=data[i]&&data[i]<='9') {
                num *= 10;
                num += data[i] - '0';
                i++;
            }
            if (data[i]=='-'){
                num = -num;
                i++;
            }
            TreeNode *root = new TreeNode(num);
            nodeStack.push(root);
            while (i<data.length()-1){
                if ('0'<=data[i+1]&&data[i+1]<='9'){
                    int initial = i;
                    int num = 0;
                    i++;
                    while ('0'<=data[i]&&data[i]<='9') {
                        num *= 10;
                        num += data[i] - '0';
                        i++;
                    }
                    if (data[i]=='-'){
                        num = -num;
                        i++;
                    }
                    TreeNode *current = new TreeNode(num);
                    if(data[initial]=='r'){
                        nodeStack.top()->right = current;
                    }
                    else{
                        nodeStack.top()->left = current;
                    }
                    nodeStack.push(current);
                }
                else if (data[i] == '#'){
                    nodeStack.pop();
                    i++;
                }
            }
            return root;
        }
    }
};
void problem297(){
    Codec codec;
    TreeNode a(-1);
    TreeNode b(0);
    TreeNode c(1);
    TreeNode d(4);
    TreeNode e(5);
    a.right = &c;
    a.left = &b;
    string s = codec.serialize(&a);
    cout<<s<<endl;
    TreeNode* rr =  codec.deserialize(s);
    TreeNode* result = codec.deserialize(codec.serialize(&a));
    return;
}
#endif //C_LEETCODE_PROBLEM297_H
