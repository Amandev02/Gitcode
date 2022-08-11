class Solution {
public:
      bool iscycleutil(vector<vector<int>> &adj, vector<int> &visited,int curr){
       if(visited[curr]==1)
           return true;
       if(visited[curr]==2) return false;
          
          visited[curr]=1;//mark visited
             for( auto it: adj[curr])
                   if(iscycleutil(adj,visited,it))
                       return true;

          visited[curr]=2;//mark processed
          return false;
           
    
    }
    //cycle detection
bool iscycle(vector<vector<int>> &adj,int curr){
    vector<int> visited(curr,0);
    for(int i=0;i<curr;i++)
        if(!visited[i])
            if(iscycleutil(adj,visited,i))
                return true;
        return false;
    
}
    //Topological sort and dfs
void dfs(vector<vector<int>> &adj,int curr, vector<bool> &visited, stack<int> &mystack){
        visited[curr] = true;
    for( auto it: adj[curr])
        if(!visited[it])
            dfs(adj,it,visited,mystack);
    
    mystack.push(curr);
    }
    
    
    vector<int> findOrder(int N, vector<vector<int>>& pre) {
         vector<vector<int>> adj(N);
        //to make adjacency matrix(Directed graph)
        for(int i = 0;i<pre.size();i++)
            adj[pre[i][1]].push_back(pre[i][0]);
        
        //detect cycle ,if there return empty array 
        vector<int> topo;
        if(iscycle(adj,N))
              return topo;
        
        // find topo sort and store it in stack
        stack<int> mystack;
        vector<bool> visited(N,false);
        
        //Apply DFS and find toposort
        for(int i =0;i<N;i++)
            if(!visited[i])
                dfs(adj,i,visited,mystack);
        
        while(!mystack.empty()){
            topo.push_back(mystack.top());
            mystack.pop();
        }
        return topo;
        
    }
};