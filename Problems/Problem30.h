#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include "../DataStructures/TreeNode.h"
#ifndef C_LEETCODE_PROBLEM234_H
#define C_LEETCODE_PROBLEM234_H
using namespace std; 

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.size()==0 || words.size() == 0) return result;
        int word_length = words[0].size();
        int total_word_length = word_length*words.size();
        unordered_map<string,int> words_map;
        unordered_map<string,int> temp_words_map;
        queue<string> temp_words_queue;
        for (auto& word: words){
            words_map[word]++;

        }
        for (int i = 0; i<word_length; i++){
            int j = word_length + i;
            temp_words_map.clear();
            while (!temp_words_queue.empty()) temp_words_queue.pop();
            while (j<=s.size()){
                string cur_word = s.substr(j-word_length,word_length);
                if (words_map.find(cur_word) != words_map.end()){
                    if (temp_words_map[cur_word] ==  words_map[cur_word]){
                        while(temp_words_queue.front()!= cur_word){
                            temp_words_map[temp_words_queue.front()]--;
                            temp_words_queue.pop();
                        } 
                        temp_words_queue.pop();
                        temp_words_queue.push(cur_word);
                    }
                    else{
                        temp_words_map[cur_word]++;
                        temp_words_queue.push(cur_word);
                        if (temp_words_queue.size() == words.size()) {
                            result.push_back(j-total_word_length);
                            temp_words_map[temp_words_queue.front()]--;
                            temp_words_queue.pop();
                        }
                    }
                }
                else{
                    temp_words_map.clear();
                    while (!temp_words_queue.empty()) temp_words_queue.pop();
                }
                j = j+word_length;
            }
        }
        return result;
    }
   
};

void problem30(){    
    string s = "aaa";
    vector<string> words = {"aa","aa"};
    Solution solution;
    auto result =  solution.findSubstring(s,words);
    for (auto i : result) cout<<i<<" ";
    cout<<endl;
}
#endif //C_LEETCODE_PROBLEM234_H
