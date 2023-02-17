 const int dx[] = {1, 0, 0, -1};
 const int dy[] = {0, -1, 1, 0}; 

class Solution {
public:
     void dfs(vector<vector<int>>& ans,vector<vector<int>> image,int sr, int sc, int newCol,int initCol){
       int n = ans.size();
       int m = ans[0].size();
      ans[sr][sc] = newCol;
      for(int i = 0;i<4;i++){
          int r = sr + dx[i];
          int c = sc + dy[i];
          if(r>=0&&c>=0&&r<n&&c<m&&ans[r][c]!=newCol&&image[r][c] == initCol) dfs(ans,image,r,c,newCol,initCol);
      }
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int initCol = image[sr][sc];
        vector<vector<int>> ans = image;
       dfs(ans,image,sr,sc,color,initCol);
       return ans;
    }
};