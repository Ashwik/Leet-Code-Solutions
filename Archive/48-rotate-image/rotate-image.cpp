class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0,j=m-1;i<j;i++,j--){
            for(int k=0;k<n;k++){
                swap(matrix[i][k],matrix[j][k]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=i,k=0;j>k;j--,k++){
                swap(matrix[j][k],matrix[k][j]);
            }
        }

        for(int i=1;i<n;i++){
            for(int j=i,k=m-1;j<k;j++,k--){
                swap(matrix[j][k],matrix[k][j]);
            }
        }
        
    }
};