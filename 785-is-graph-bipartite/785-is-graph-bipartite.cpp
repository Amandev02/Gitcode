#include <bits/stdc++.h>

class Solution {
public:
    vector<int> col,vis;
    bool dfs(int node,int color,vector<vector<int>>& graph){
        vis[node] = 1;
        col[node] = color;
        for(auto it: graph[node]){
            if(vis[it]==0){
                //if in place of false true is written or noting is written its not working
                 if(dfs(it,color^1,graph)==false)
                     return false;
            }
            else if(color==col[it]) return false;
            
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
         int n=graph.size();
          col.resize(n);
          vis.resize(n);
        
        for(int i=0;i<n;++i){
            if(vis[i]==0 && dfs(i,0,graph)==false){ 
                return false;
            }
        }
        return true;
    }
};