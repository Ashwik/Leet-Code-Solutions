class Solution {
public:

    bool solve(vector<vector<char>>& board,int i,int j, vector<vector<bool>>& row,vector<vector<bool>>& col, vector<vector<bool>>& box){

       

        if(i==8 && j==9){
            return true;
        }else if(j==9){
            return solve(board,i+1,0,row,col,box);
        }
        if(board[i][j]!='.'){
            return solve(board,i,j+1,row,col,box);
        }

        for(int num=0;num<9;num++){

            if(row[i][num]==true){continue;}
            if(col[j][num]==true){continue;}
            if(box[(i/3)*3 + j/3][num]==true){continue;}
            
            row[i][num]=true;
            col[j][num]=true;
            box[(i/3)*3 + j/3][num]=true;

            board[i][j] = '0'+num+1;
            if(solve(board,i,j+1,row,col,box)){return true;}
            board[i][j] = '.';

            row[i][num]=false;
            col[j][num]=false;
            box[(i/3)*3 + j/3][num]=false;
        }
        return false;
    }


    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool>(9,false));
        vector<vector<bool>> col(9,vector<bool>(9,false));
        vector<vector<bool>> box(9,vector<bool>(9,false));


      for(int i=0;i<9;i++){
          for(int j=0;j<9;j++){
              if(board[i][j]=='.'){continue;}
              int num = board[i][j]-'1';
              row[i][num] = true;
              col[j][num] = true;
              box[(i/3)*3 + j/3][num] = true;
          }
      }

      solve(board,0,0,row,col,box);
      return;
 
    }
};