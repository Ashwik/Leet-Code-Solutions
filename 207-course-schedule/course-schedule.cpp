class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& preq) {
        
        vector<int> adj[n];
        vector<int> degree(n,0);

        for(int i=0;i<preq.size();i++){
            adj[preq[i][0]].push_back(preq[i][1]);
            degree[preq[i][1]]++;
        }
        vector<int> bfs;
        
        for(int i=0;i<n;i++){
            if(degree[i]==0){bfs.push_back(i);}
        }

        for(int i=0;i<bfs.size();i++){
            int ind = bfs[i];
            for(int j=0;j<adj[ind].size();j++){
                int num = adj[ind][j];
                degree[num]--;
                if(degree[num]==0){bfs.push_back(num);}
            }
        }

        return bfs.size()==n;
    }
};