struct node {
    int x,y,time;
    node(int _x,int _y,int _time){
        x=_x;
        y=_y;
        time =_time;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n = grid.size();
       int m =grid[0].size();
        
        queue<node> q;
        int cntorng = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2) q.push(node(i,j,0));
                if(grid[i][j]!=0) cntorng++;
            }
        }
        
        int ans =0 ,cnt=0;
        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            int time = q.front().time;
            q.pop();
            cnt++;
            ans = max(ans,time);
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int ind = 0;ind<4;ind++){
                int newX = x+dx[ind];
                int newY = y+dy[ind];
                
               if(newX>=0 && newY>=0 && newX<n && newY<m &&grid[newX][newY]==1){
                    grid[newX][newY]=2;
                    q.push(node(newX,newY,time+1));
                }
            }

        }
            if(cnt==cntorng) return ans;
            return -1;
    }
};