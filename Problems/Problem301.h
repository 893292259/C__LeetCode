//
// Created by zzliu on 18-5-23.
//

#ifndef C_LEETCODE_PROBLEM301_H
#define C_LEETCODE_PROBLEM301_H
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> removeRight(vector<string>&result,int pos){
        vector<string> answers;
        for (auto s: result){
            int i = pos;
           while(i>=0){
               if (s[i]=='#') break;
               else if (s[i]==')'){
                     while (i>=0&&s[i]==')'){
                         i--;
                     }
                     string temp = s;
                     temp[i+1]='#';
                     answers.push_back(temp);
                   }
               else i--;
           }
        }
        return answers;
    }
    vector<string> removeLeft(vector<string>&result,int pos){
        vector<string> answers;
        for (auto s: result){
            int i = pos;
            while(i<s.length()){
                if (s[i]=='#') break;
                else if (s[i]=='('){
                        while (i<s.length()&&s[i]=='('){
                            i++;
                        }
                        string temp = s;
                        temp[i-1]='#';
                        answers.push_back(temp);
                    }
                    else i++;
            }
        }
        return answers;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        result.push_back(s);
        vector<char> pos;
        int balance = 0;
        for (int i=0;i<s.length();i++){
            if (s[i]=='(') balance++;
            if (s[i]==')') balance--;
            if (balance<0){
                result = removeRight(result,i);
                balance++;
            }
        }

        balance = 0;
        for (int i=s.length();i>=0;i--){
            if (s[i]=='(') balance--;
            if (s[i]==')') balance++;
            if (balance<0){
                result = removeLeft(result,i);
                balance++;
            }
        }
        for (auto &s:result){
            s.erase(remove(s.begin(),s.end(),'#'),s.end());
        }
        return result;
    }
};
void problem301(){
    Solution solution;
    string s = ")(";
    solution.removeInvalidParentheses(s);
}
#endif //C_LEETCODE_PROBLEM301_H
