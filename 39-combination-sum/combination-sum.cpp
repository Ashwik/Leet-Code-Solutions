class Solution {
public:

    void findComb(vector<int>& cand, int target,int ind, int sum, vector<vector<int>> & res, vector<int>& v){
        
        if(sum==target){
            res.push_back(v);
            return;
        }
        if(ind==cand.size()){
            return;
        }
        
        for(int i=ind;i<cand.size();i++){
            if(sum+cand[i]>target){return;}
            v.push_back(cand[i]);
            findComb(cand,target,i,sum+cand[i],res,v);
            v.pop_back();
        }
        return ;
    }


    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(cand.begin(),cand.end());
        findComb(cand,target,0,0,ans,v);
        return ans;
    }
};