class Solution {
public:

    bool isvalid(vector<string>& arr, int row, int col,int n){

        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(arr[i][j]=='Q'){
                return false;
            }
        }

        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(arr[i][j]=='Q'){
                return false;
            }
        }

        return true;
    }

    void solve(int n,int row, vector<vector<string>> &ans, vector<string>& arr, vector<bool>& colarr){

        if(row==n){
            ans.push_back(arr);return;
        }

        for(int i=0;i<n;i++){
            if(colarr[i]==false && isvalid(arr,row,i,n)){
                colarr[i] = true;
                arr[row][i] = 'Q';
                solve(n,row+1,ans,arr,colarr);
                arr[row][i] = '.';
                colarr[i] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        string str="";
        for(int i=0;i<n;i++){
            str+=".";
        }
        vector<string> arr(n,str);
        vector<bool> colarr(n,false);
        vector<vector<string>> ans;

        solve(n,0,ans,arr,colarr);
        return ans;

    }
};