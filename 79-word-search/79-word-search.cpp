
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0;i<board.size();i++){
            for(int j =0;j<board[0].size();j++)
             if(dfs(i,j,word,board)) return true;
        }
        return false;
    }
    
    bool dfs(int i ,int j ,string& word,vector<vector<char>>& board){
        if(!word.length()) return true;
       if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  
        return false;
        
        char c = board[i][j];
        board[i][j] ='*';
        string s = word.substr(1);
        
        bool ret = dfs(i+1,j,s,board)||dfs(i,j+1,s,board)||dfs(i-1,j,s,board)|| dfs(i,j-1,s,board);
        
       board[i][j] = c;
        return ret;
        
        
    }
    
};