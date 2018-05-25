//
// Created by LiuZhizheng on 2018/5/14.
//

#include "Problems/Problem297.h"
using namespace std;
struct node{
     node* next;
     int val;
};
void test(node &a){
    a.next->val = 1;
}
int main() {
    problem297();
    return 0;
}
