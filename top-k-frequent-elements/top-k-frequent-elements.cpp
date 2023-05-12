class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        int n = nums.size();
        vector<int> bucket[n+1];

        for(auto it=mp.begin();it!=mp.end();it++){
            bucket[it->second].push_back(it->first);
        }

        vector<int> ans;

        for(int i=n;i>0;i--){
            for(int j=0;j<bucket[i].size();j++){
                ans.push_back(bucket[i][j]);
                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;

    }
};