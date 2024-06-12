class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()<=k){
            return nums;
        }
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                mp[nums[i]]++;
            }else{
                mp[nums[i]] = 1;
            }
        }

        for(auto it=mp.begin();it!=mp.end();it++){
            int num = it->first;
            int freq = it->second;

            if(pq.size()==k && freq > pq.top().first){
                pq.pop();
            }

            if(pq.size()<k){
                pq.push({freq,num});
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        } 

        return ans;

    }
};