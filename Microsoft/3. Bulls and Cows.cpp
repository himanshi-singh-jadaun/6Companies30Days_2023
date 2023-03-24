#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0;
        int y = 0;
        unordered_map<char,int>mp;
        for(int i = 0; i<secret.size(); i++){
            if(secret[i]==guess[i]){
                x++;
                guess[i] = '*';
            }else{
                mp[secret[i]]++;
            }
        }
        for(auto s : guess){
            if(s != '*' && mp.find(s) != mp.end()){
                y++;
                mp[s]--;
                if(mp[s] == 0){
                    mp.erase(s);
                }
            }
        }
        return to_string(x)+"A"+to_string(y)+"B";
    }
};