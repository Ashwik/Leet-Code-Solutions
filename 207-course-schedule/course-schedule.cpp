class Solution {
public:

    bool dfs(vector<int> adj[],vector<bool>& visit,vector<bool>& cycle, int s){
        
        visit[s] = true;
        cycle[s] = true;
        
        for(int i=0;i<adj[s].size();i++){
            int num = adj[s][i];
            if(cycle[num]){return true;}
            if(!visit[num] && dfs(adj,visit,cycle,num)){return true;}
        }
        cycle[s] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<int> adj[n];

        for(int i=0;i<preq.size();i++){
            adj[preq[i][1]].push_back(preq[i][0]);
        }
        vector<bool> visit(n, false);
        vector<bool> cycle(n, false);

        for(int i=0;i<n;i++){
            if(visit[i]){continue;}
            if(dfs(adj,visit,cycle,i)){return false;}
        }
        return true;
    }
};