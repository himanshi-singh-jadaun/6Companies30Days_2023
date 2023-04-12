#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mx = nums[0];
        int mi = nums[nums.size()-1];
        int start = 0;
        int end = -1;
        for(int i =1 ; i<nums.size(); i++){
            if(nums[i]<mx){
                end = i;
            }else{
                mx = nums[i];
            }
        }
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i]>mi){
                start = i;
            }else{
                mi = nums[i];
            }
        }
        return end - start + 1;
    }
};