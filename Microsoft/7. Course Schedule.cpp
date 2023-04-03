#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(int i = 0 ; i<prerequisites.size(); i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>indegree(numCourses,0);
        queue<int>q;
        for(int i = 0; i< numCourses; i++){
            for(auto it : graph[i]){
                indegree[it]++;
            }
        }
        int count = 0;
        for(int i = 0 ; i< numCourses ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int vertex = q.front();
            q.pop();
            count++;
            for(auto i: graph[vertex]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(count == numCourses)
        {
            return true;
        }
        return false;
    }
};