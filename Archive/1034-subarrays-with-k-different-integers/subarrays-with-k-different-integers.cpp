class Solution {
public:

    int subarraysWithKAtmost(vector<int>& nums,int k){
        unordered_map<int,int> mp;
        int j=0,res=0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==0){
                k--;
            }
            mp[nums[i]]++;

            while(k<0){
                mp[nums[j]]--;
                if(mp[nums[j]]==0){k++;}
                j++;
            }
            res += i-j+1;
        }
        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return subarraysWithKAtmost(nums,k) - subarraysWithKAtmost(nums,k-1);
    }
};