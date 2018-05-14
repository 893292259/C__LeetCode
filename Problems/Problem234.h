//
// Created by LiuZhizheng on 2018/5/14.
//
#include <iostream>
#include <stack>
#include "../DataStructures/ListNode.h"
#ifndef C_LEETCODE_PROBLEM234_H
#define C_LEETCODE_PROBLEM234_H
using namespace std;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> data;
        ListNode* current = head;
        while (current!=NULL){
            data.push(current->val);
            current = current->next;
        }
        while (data.size()>0){
            if (head->val!=data.top()){
                return false;
            }
            data.pop();
            head = head->next;
        }
        return true;
    }
};
void problem234(){
    ListNode a(1);
    ListNode b(2);
    ListNode c(1);
    a.next = &b;
    b.next = &c;
    Solution solution;
    cout<<solution.isPalindrome(&a)<<endl;
}
#endif //C_LEETCODE_PROBLEM234_H
