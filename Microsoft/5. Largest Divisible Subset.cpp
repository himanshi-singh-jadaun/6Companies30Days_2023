#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(), nums.end());
        vector<int>dp(nums.size(), 1), hash(nums.size());
        int maxi=1;
        int lastIndex = 0;
        for(int i =0; i<nums.size(); i++){
            hash[i] = i;
            for(int j = 0 ; j<i; j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        reverse(ans.begin(), ans.end());
        return ans ;
    }
};