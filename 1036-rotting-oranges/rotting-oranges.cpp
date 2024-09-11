class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        int arr[] = {1,0,-1,0,1};

        int ans = 0;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0,j=1;j<5;i++,j++){
                    int dx = x+arr[i];
                    int dy = y+arr[j];
                    if(dx<0 || dy<0 || dx ==m || dy==n || grid[dx][dy] != 1){
                        continue;
                    }
                    q.push({dx,dy});
                    grid[dx][dy] = 2;
                }
            }
            if(q.empty()){break;}
            ans++;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){return -1;}
            }
        }
        return ans;
    }
};