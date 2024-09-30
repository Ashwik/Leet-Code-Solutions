class Solution {
public:

    bool dfs(vector<int>& nums,vector<bool>&visit, int ind,int sum, int req, int k){
        if(k==1){return true;}

        if(sum==req){
            return dfs(nums,visit,0,0,req,k-1);
        }

        bool ans = false;
        for(int i=ind;i<nums.size();i++){
            if(visit[i]==false && sum+nums[i] <= req){
                visit[i] = true;
                ans = dfs(nums,visit,ind+1,sum+nums[i],req,k);
                if(ans){return ans;}
                visit[i] = false;

                if(sum==0){
                    break;
                }
            }
        }
        return ans;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum%k!=0){return false;}
        int req = sum/k;
        vector<bool> visit(nums.size(),false);

        return dfs(nums,visit,0,0,req,k);
    }
};