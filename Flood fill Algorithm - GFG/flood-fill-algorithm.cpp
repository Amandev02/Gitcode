//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int initCol = image[sr][sc];
        vector<vector<int>> ans = image;
       dfs(ans,image,sr,sc,newColor,initCol);
       return ans;
          
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends