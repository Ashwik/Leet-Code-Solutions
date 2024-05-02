class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();

        int oldcolor = image[sr][sc];
        if(oldcolor == color){return image;}

        queue<pair<int,int>> q;
        q.push({sr,sc});

        while(!q.empty()){
            int len = q.size();
            while(len--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                image[x][y] = color;
                int arr[] = {-1,0,1,0,-1};
                for(int i=0,j=1;i<4;i++,j++){
                    int dx = arr[i]+x;
                    int dy = arr[j]+y;
                    if(dx>=0 && dy>=0 && dx<m && dy<n && image[dx][dy]==oldcolor){
                        q.push({dx,dy});
                    }
                }
            }
        }

        return image;


    }
};