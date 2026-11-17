class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        int st = 0,en = m;
        int mid ;
        int row = -1;
        int num1,num2;
        while(st<en){
            mid = (st+en)/2;
            num1 = matrix[mid][0];
            num2 =  matrix[mid][n-1];
            if(num1==target || num2==target){
               return true;
            }else if(num1<target){
                if(num2>target){
                    row = mid;
                    break;
                }
                st = mid+1;
            }else{
                en = mid;
            }
        }
        
        if(row==-1){
            return false;
        }

        st = 0,en = n;
        while(st<en){
            mid = (st+en)/2;
            num1 = matrix[row][mid];
            if(num1==target){
                return true;
            }else if(num1<target){
                st = mid+1;
            }else{
                en = mid;
            }
        }
        return false;
    }
};