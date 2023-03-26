class Solution {
public:
    void dfs(int node, vector<int> &dist_node,vector<bool> &visited,vector<bool> &extra, vector<int> &edges,int distance,int &ans){
        if(node !=-1){
        if(!visited[node]){
           visited[node] = true;
             extra[node] = true;
            dist_node[node] = distance;
        dfs(edges[node],dist_node,visited,extra,edges,distance+1,ans);
        }
            else if(extra[node]){
                ans = max(ans,distance-dist_node[node]);
            }
              extra[node] = false;
        }
        
        

    }
    
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        int ans = -1;
        vector<int> dist_node(n,0);
        vector<bool> visited(n,false);
        vector<bool> extra(n,false);
        for(int i =0;i<n;i++){
            if(!visited[i])
            dfs(i,dist_node,visited,extra,edges,0,ans);
            
        }
        
        return ans;
    }
};