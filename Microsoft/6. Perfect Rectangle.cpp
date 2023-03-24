#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>mp;
        for(int i =0 ; i<rectangles.size(); i++){
            mp[{rectangles[i][0], rectangles[i][1]}]++;
            mp[{rectangles[i][2], rectangles[i][3]}]++;
            mp[{rectangles[i][0], rectangles[i][3]}]--;
            mp[{rectangles[i][2], rectangles[i][1]}]--;
        }
        int ans =0;
        for(auto it : mp){
            if(abs(it.second) == 1){
                ans++;
            }
            if(abs(it.second)!=1 && it.second!=0){
                return false;
            }
        }
        return (ans==4);
    }
};