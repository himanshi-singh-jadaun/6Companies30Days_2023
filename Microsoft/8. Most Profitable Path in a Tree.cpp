#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs_parent(int s, int p, vector<vector<int>>&graph, vector<int>&parent){
            parent[s] = p;
            for(auto x : graph[s]){
                if(x==p){
                    continue;
                }
                dfs_parent(x,s, graph, parent);
            }
    }
    void dfs(int s, int p, vector<int>&amount, vector<vector<int>>&graph, int &ans){
        if(p!=-1){
            amount[s]+=amount[p];
        }
        int c=0;
        for(auto x: graph[s]){
            if(x==p){
                continue;
            }
            c++;
            dfs(x,s,amount, graph, ans);
        }
        if(c==0){
            ans = max(ans, amount[s]);
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>>graph(amount.size());
        for(int i =0 ; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int>parent(amount.size(),-1);
        dfs_parent(0,-1,graph,parent);
    vector<int>path;
    int curr =bob;
    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    for(int i =0 ; i<path.size()/2; i++){
        amount[path[i]]=0;
    }
    if(path.size()%2){
        amount[path[path.size()/2]]/=2;
    }
    int ans = INT_MIN;
    dfs(0,-1,amount, graph, ans);
    return ans ;
    }
};