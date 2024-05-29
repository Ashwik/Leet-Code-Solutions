class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> grid(n,1);

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[j] += grid[j-1];
            }
        }
        return grid[n-1];

    }
};