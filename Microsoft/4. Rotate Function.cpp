#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long sum = 0;
        long original = 0;

        for(int i = 0 ; i<nums.size(); i++){
            sum+= nums[i];
            original += i*nums[i];
        }
        long ans = original;
        for(int i = nums.size()-1; i>=0; i--){
            original += sum - (nums[i] * nums.size());
            ans = max(original, ans);
        }
        return ans ;
    }
};