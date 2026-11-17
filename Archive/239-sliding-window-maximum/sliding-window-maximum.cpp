class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[i]>=nums[dq.front()]){
                dq.pop_front();
            }
            dq.push_front(i);
        }
        ans.push_back(nums[dq.back()]);
        
        for(int i=k,j=0;i<nums.size();i++,j++){
            
            while(!dq.empty() && j>=dq.back()){
                dq.pop_back();
            }
            while(!dq.empty() && nums[i]>=nums[dq.front()]){
                dq.pop_front();
            }
            dq.push_front(i);
            ans.push_back(nums[dq.back()]);
        }
        return ans;
    }
};