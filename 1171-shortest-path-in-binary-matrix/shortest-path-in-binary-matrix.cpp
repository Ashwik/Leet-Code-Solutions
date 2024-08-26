class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({0,0});
        int res=0;
        
        while(!q.empty()){
            int len = q.size();
            res++;
            while(len--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(grid[x][y]!=0){continue;}

                if(x==m-1 && y==n-1){return res;}
                
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        if(i==0&&j==0){continue;}
                        
                        int dx = x + i;
                        int dy = y + j;
                        if(dx<0 || dy<0 || dx>=m || dy>=n || grid[dx][dy]==1){
                            continue;
                        }

                        if(dx==m-1 && dy==n-1){return res+1;}
                        q.push({dx,dy});
                    }
                }
                grid[x][y] = 1;
            }
        }
        return -1;
    }
};