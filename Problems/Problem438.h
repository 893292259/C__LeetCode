//
// Created by zzliu on 18-5-21.
//

#ifndef C_LEETCODE_PROBLEM438_H
#define C_LEETCODE_PROBLEM438_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int p_length = p.length();
        vector<int> data;
        map<int,int> dict;
        vector<int> result;
        for (int i=0;i<p.length();i++){
            int current = p[i]-'a';
            if (dict.find(current)==dict.end()){
                dict.insert(pair<int,int>(current,0));
            }
            dict.at(current)++;
        }
        for (int i=0;i<s.length();i++){
            int current = s[i]-'a';
            if (dict.find(current)==dict.end()){
                for (int i=0;i<data.size();i++){
                    dict.at(data[i])++;
                }
                data.clear();
            }
            else {
                data.push_back(current);
                if (dict.at(current) == 0) {
                    while(data[0]!=current){
                        dict[data[0]]++;
                        data.erase(data.begin());
                    }
                    data.erase(data.begin());
                }
                else{
                    dict.at(current)--;
                }
                if (data.size()==p.length()){
                    result.push_back(i-p.length()+1);
                    dict.at(data[0])++;
                    data.erase(data.begin());
                }
            }
        }
        return result;
    }
};
void problem438(){
    Solution solution;
    string s="abaacbabc";
    string p="abc";
    solution.findAnagrams(s,p);
}
#endif //C_LEETCODE_PROBLEM438_H
