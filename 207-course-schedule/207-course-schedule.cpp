class Solution {
public:
    bool iscycle(vector<vector<int>> &adj, vector<int> &visited,int curr){
        if(visited[curr]==2)
            return true;
        visited[curr]=2;
        for(int i = 0;i<adj[curr].size();i++)
            if(visited[adj[curr][i]]!=1)
                if(iscycle(adj,visited,adj[curr][i]))
                    return true;
        visited[curr] = 1;
        return false;
    }
    
    bool canFinish(int numc, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numc);
        
        //to make adjacency matrix(Directed graph)
        for(int i = 0;i<pre.size();i++)
            adj[pre[i][0]].push_back(pre[i][1]);
        
        //traverse each elementn of the graph 
        vector<int> visited(numc,0);
        for(int i = 0;i<numc;i++)
            if(visited[i]==0)
                if(iscycle(adj,visited,i))
                    return false;
        
        return true;
    }
};