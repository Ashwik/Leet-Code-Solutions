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


    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        vector<int> adj[numCourses];

        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        vector<bool> visit(numCourses,false);
        vector<bool> cycle(numCourses,false);
        
        for(int i=0;i<numCourses;i++){
            if(visit[i]==false && dfscycle(adj,visit,cycle,i)){
                return false;
            }
        }
        return true;

    }
};