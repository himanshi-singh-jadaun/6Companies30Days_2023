#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve( int k, int n, vector<int>&v, vector<vector<int>>&ans, int index, vector<int>num){
        if(n==0){
            if(v.size()==k){
                ans.push_back(v);
            }
            return ;
        }
        for(int i = index; i<num.size(); i++){
            if(n-num[i]>=0){
                v.push_back(num[i]);
                solve(k, n-num[i], v, ans, i+1, num);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans ;
        vector<int>v;
        vector<int>num;
        for(int i = 0 ; i<9; i++){
            num.push_back(i+1);
        }
        solve(k,n,v,ans,0, num);
        return ans ;
    }
};