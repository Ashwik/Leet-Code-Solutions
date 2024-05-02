class Solution {
public:

    bool dfscycle(vector<int> adj[],vector<bool>& visit,vector<bool>& cycle,int ind){

         visit[ind] = true;
         cycle[ind] = true;
         for(int i=0;i<adj[ind].size();i++){
             int num = adj[ind][i];
             if(visit[num]==false){
                 if(dfscycle(adj,visit,cycle,num)){return true;}
             }else if(cycle[num]==true){
                 return true;
             }
         }   
         cycle[ind] = false;
         return false;
    }


    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<int> adj[n];
        vector<int> bfs,degree(n,0);

        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            degree[pre[i][0]]++;
        }

        // vector<bool> visit(n,false);
        // vector<bool> cycle(n,false);
        
        for(int i=0;i<n;i++){
            if(degree[i]==0){
                bfs.push_back(i);
            }
        }
        if(bfs.size()==n){return true;}
        for(int i=0;i<bfs.size();i++){
            int num = bfs[i];
            for(int j=0;j<adj[num].size();j++){
                int ind = adj[num][j];
                degree[ind]--;
                if(degree[ind]==0){
                    bfs.push_back(ind);
                }
            }
        }
        if(bfs.size()==n){return true;}

        return false;

    }
};