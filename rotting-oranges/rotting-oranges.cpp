class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int minutes = 0;

        while(fresh>0 && !q.empty()){
            int len = q.size();
            while(len--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                int arr[] = {-1,0,1,0,-1};
                for(int i =0,j=1;i<4;i++,j++){
                    int dx = x + arr[i];
                    int dy = y + arr[j];
                    if(dx>=0 && dy>=0 && dx<grid.size() && dy<grid[0].size()&& grid[dx][dy]==1){
                        fresh--;
                        grid[dx][dy] = 2;
                        q.push({dx,dy});
                    }
                }
            }
            minutes++;
        }
        if(fresh>0){return -1;}
        return minutes;


    }
};