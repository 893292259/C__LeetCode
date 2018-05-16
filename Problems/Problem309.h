//
// Created by zzliu on 18-5-16.
//

#ifndef C_LEETCODE_PROBLEM309_H
#define C_LEETCODE_PROBLEM309_H

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int processStack(vector<int> &stack){
        if (stack[0]<0){
            stack.erase(stack.begin());
        }
        if (stack[stack.size()-1]<0){
            stack.erase(stack.begin()+stack.size()-1);
        }
        if (stack.size()>=1){
            int last2 = 0;
            int last1 = stack[0];
            int Max;
            for (int i=2;i<stack.size();i+=2){
                Max = max(last2+stack[i],max(last1,last1+stack[i-1]+stack[i]));
                last2 = last1;
                last1 = Max;
            }
            return last1;
        }
        else{
            return 0;
        }
    }
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int cost = 0;
        vector<int> stack;
        stack.push_back(0);
        for (int i=1;i<prices.size();i++){
            int diff = prices[i]-prices[i-1];
            if (stack[stack.size()-1]*diff>=0){
                sum += processStack(stack);
                stack.erase(stack.begin(),stack.begin()+stack.size());
                stack.push_back(diff);
            }
            else{
                stack.push_back(diff);
            }
        }
        sum += processStack(stack);
        return sum;
    }
};

void problem309(){
  Solution solution;
  int data[] = {1, 2, 3, 0, 2, 7};
  vector<int> prices(data,data+5);
  cout<<solution.maxProfit(prices)<<endl;

}

#endif //C_LEETCODE_PROBLEM309_H
