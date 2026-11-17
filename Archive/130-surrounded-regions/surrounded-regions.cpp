class Solution {
public:

    void traverse(vector<vector<char>>& board,int i,int j){
        int m = board.size();
        int n = board[m-1].size();
        
        if(i<0 || j<0 || i==m || j==n){return ;}
        if(board[i][j]!='O'){return ;}

        board[i][j] = 'Z';

        traverse(board,i+1,j);
        traverse(board,i-1,j);
        traverse(board,i,j+1);
        traverse(board,i,j-1);
    }

    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[m-1].size();

        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                traverse(board,i,0);
            }
            if(board[i][n-1]=='O'){
                traverse(board,i,n-1);
            }
        }

        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                traverse(board,0,i);
            }
            if(board[m-1][i]=='O'){
                traverse(board,m-1,i);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='Z'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};