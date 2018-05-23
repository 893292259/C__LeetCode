//
// Created by zzliu on 18-5-23.
//

#ifndef C_LEETCODE_PROBLEM647_H
#define C_LEETCODE_PROBLEM647_H
#include <iostream>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int size = s.length();
        for (int i=0;i<=size;i++){
            s.insert(2*i,"#");
        }
        int count = 0;
        for (int i=0;i<s.length();i++){
            int k=1;
            while ((i-k)>=0&&(i+k)<s.length()&&s[i-k]==s[i+k]){
                if (s[i-k]!='#') {
                    count++;
                }
                k++;
            }
        }
        return count+size;
    }
};
void problem647(){
    Solution solution;
    string s = "aaa";
    cout<<solution.countSubstrings(s)<<endl;
}
#endif //C_LEETCODE_PROBLEM647_H
