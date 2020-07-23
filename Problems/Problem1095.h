#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <assert.h>
#include "../DataStructures/TreeNode.h"
#ifndef C_LEETCODE_PROBLEM234_H
#define C_LEETCODE_PROBLEM234_H
using namespace std;

class MountainArray{
    public:
        int get(int id){
            assert (id>=0 && id<array.size());
            return array[id];
        }
        int length(){
            return array.size();
        }
        MountainArray(vector<int>& a){
            array = a;
        }
    private:
        vector<int> array;
};

class Solution {
public:
    int findPeak(MountainArray &mountainArr){
        int head = 0;
        int tail = mountainArr.length()-1;
        while (true){
            int mid = (head+tail)/2;
            if (mid ==0) {
                head = mid + 1;
                continue;
            }
            if (mid == mountainArr.length()-1){
                tail = mid - 1;
                continue;
            }
            if (mountainArr.get(mid)>mountainArr.get(mid-1) && mountainArr.get(mid)>mountainArr.get(mid+1)) return mid;
            else if (mountainArr.get(mid)>mountainArr.get(mid-1) && mountainArr.get(mid)<mountainArr.get(mid+1)){
                head = mid + 1;
            }
            else tail =  mid - 1;
        }    
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        if (target<mountainArr.get(0) && target<mountainArr.get(mountainArr.length()-1)) return -1;
        int mid = findPeak(mountainArr); 
        if (target > mountainArr.get(mid)) return -1; 

        if (target >= mountainArr.get(0)){ 
            int head = 0;
            int tail = mid;
            while (true){
                if (head > tail) break;
                int mid = (head+tail)/2;
                if (mountainArr.get(mid) == target) return mid;
                else if (mountainArr.get(mid)>target){
                    tail = mid -1;
                } 
                else {
                    head = mid + 1;
                }
            }    
        }
        if (target >= mountainArr.get(mountainArr.length()-1)){ 
            int head = mid+1;
            int tail = mountainArr.length() - 1;
            while (true){
                if (head > tail) break;
                int mid = (head+tail)/2;
                if (mountainArr.get(mid) == target) return mid;
                else if (mountainArr.get(mid)>target){
                    head = mid + 1;
                } 
                else {
                    tail = mid - 1;
                }
            }    
        }
        return -1;
    }
};

void problem1095(){    
    vector<int> array ={3,5,3,2,0};
    MountainArray m(array);
    Solution solution;
    cout<<solution.findInMountainArray(0,m); 
    cout<<endl;
}
#endif //C_LEETCODE_PROBLEM234_H
