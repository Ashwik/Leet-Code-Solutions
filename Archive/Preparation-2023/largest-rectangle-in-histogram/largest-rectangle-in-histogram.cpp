class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        
        stack<int> st;
        int n = nums.size();
        vector<int> right(n,n);

        for(int i=n-1;i>=0;i--){

            while(!st.empty()&& nums[i] < nums[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){st.pop();}
        int left;
        int ans = 0;
        int cur = 0;
        for(int i=0;i<n;i++){
            while(!st.empty()&& nums[i] <= nums[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                cur = (right[i]-st.top()-1)*nums[i];
            }else{
                cur = right[i]*nums[i];
            }
            ans = max(ans,cur);
            st.push(i);
        }

        return ans;
    }
};