//
// Created by zzliu on 18-5-20.
//

#ifndef C_LEETCODE_PROBLEM394_H
#define C_LEETCODE_PROBLEM394_H
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<string> data;
        s.insert(0,"1[");
        s.insert(s.length(),"]");
        for (int i=0;i<s.length();i++){
            string current = s.substr(i,1);
            if (current=="]"){
                string temp = "";
                while (data.top()!="["){
                    temp.insert(0,data.top());
                    data.pop();
                }
                data.pop();
                string number = "";
                while (data.size()>0&&"0"<=data.top()&&data.top()<="9"){
                    number.insert(0,data.top());
                    data.pop();
                }
                stringstream ss;
                ss<<number;
                int times;
                ss>>times;
                string final="";
                for (int i=0;i<times;i++){
                    final.insert(0,temp);
                }
                data.push(final);
            }
            else{
                data.push(current);
            }
        }
        return data.top();
    }
};
void problem394(){
    Solution solution;
    string s = "10[leetcode]";
    cout<<solution.decodeString(s)<<endl;
}
#endif //C_LEETCODE_PROBLEM394_H
