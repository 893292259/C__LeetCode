//
// Created by LiuZhizheng on 2018/5/18.
//

#ifndef C_LEETCODE_PROBLEM322_H
#define C_LEETCODE_PROBLEM322_H
#include <iostream>  
#include <vector>
using namespace std;
class Solution {
public:
   int find_path(vector<vector<int>>& matrix,  vector<vector<int>>& path_length, int i,int j){
       if (path_length[i][j] >0) return path_length[i][j];  
       int max_length = 1;
       if (i-1>=0 && matrix[i-1][j]>matrix[i][j]) { 
           max_length = max(max_length,find_path(matrix,path_length,i-1,j)+1);
       }  
       if (j-1>=0 && matrix[i][j-1]>matrix[i][j]) { 
           max_length = max(max_length,find_path(matrix,path_length,i,j-1)+1);
       }
       if (i+1<matrix.size() && matrix[i+1][j]>matrix[i][j]) { 
           max_length = max(max_length,find_path(matrix,path_length,i+1,j)+1);
       }
       if (j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j]) { 
           max_length = max(max_length,find_path(matrix,path_length,i,j+1)+1);
       }
       path_length[i][j] = max_length;
       return max_length;
   }
   int longestIncreasingPath(vector<vector<int>>& matrix) {
       if (matrix.size() ==0 || matrix[0].size() ==0) return 0;
       vector<vector<int>> path_length(matrix.size(),vector<int>(matrix[0].size(),-1));
       int result = 1;
       for (int i = 0; i<matrix.size(); i++){
         for (int j=0; j<matrix[0].size();j++){
            int t = find_path(matrix,path_length,i,j);
            result =  max(t,result);
         }
       }
       return result;
   }
};
void problem329(){
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>{3,4,5});
    matrix.push_back(vector<int>{3,2,6});
    matrix.push_back(vector<int>{2,2,1});
    Solution solution;
    cout<<solution.longestIncreasingPath(matrix)<<endl;
}
#endif //C_LEETCODE_PROBLEM322_H
