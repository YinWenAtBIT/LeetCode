class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
                //check input  
        if(board.size() ==0)
            return;  
          
        int m = board.size();  
        int n = board[0].size();  
          
        for(int i=0; i<m; i++) {  
            for(int j=0; j<n; j++) {  
                int x = getLiveNum(board, i, j);  
                if(board[i][j] == 0) {  
                    if(x==3) board[i][j]+=10;  
                } else {  
                    if(x==2 || x==3) board[i][j]+=10;       
                }  
            }  
        }  
          
        for(int i=0; i<m; i++) {  
            for(int j=0; j<n; j++) {  
                board[i][j] /= 10;   
            }  
        }  
    }  
      
    int getLiveNum(vector<vector<int>>& board, int x, int y) {  
        int c=0;  
        for(int i=x-1; i<=x+1; i++) {  
            for(int j=y-1; j<=y+1; j++) {  
                if(i<0 || j<0 || i>board.size()-1 || j>board[0].size()-1 || (i==x && j==y)) continue;  
                if(board[i][j]%10==1) c++;  
            }  
        }  
        return c;  
    }  
};