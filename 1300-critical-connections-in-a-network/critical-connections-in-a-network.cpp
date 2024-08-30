class Solution {
public:

    void dfs(int ind, vector<int> adj[], vector<vector<int>> & bridges, vector<int>& lowlink, vector<int>&id,vector<bool>& visit, int idnum, int parent){

        lowlink[ind] = id[ind] = idnum;
        idnum++;
        visit[ind] = true;

        for(int i=0;i<adj[ind].size();i++){
            int toInd = adj[ind][i];
            if(toInd==parent){continue;}
            if(visit[toInd]){
                lowlink[ind] = min(lowlink[ind],id[toInd]);
            }else{
                dfs(toInd,adj,bridges,lowlink,id,visit,idnum,ind);
                lowlink[ind] = min(lowlink[ind],lowlink[toInd]);
                if(id[ind]<lowlink[toInd]){
                    bridges.push_back({ind,toInd});
                }
            } 
        }
    }


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<int> adj[n];
        vector<vector<int>> bridges;
        
        for(int i=0;i<con.size();i++){
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
        }

        vector<bool> visit(n,false);
        vector<int> lowlink(n,0);
        vector<int> id(n,0);

        dfs(0,adj,bridges,lowlink,id,visit,1,-1);

        return bridges;

    }
};