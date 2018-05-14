//
// Created by LiuZhizheng on 2018/5/14.
//
#include <iostream>
#ifndef C_LEETCODE_LISTNODE_H
#define C_LEETCODE_LISTNODE_H
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};
#endif //C_LEETCODE_LISTNODE_H
