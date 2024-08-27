class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();

        vector<long long int> cnums(n);
        cnums[0] = nums[0];
        for(int i=1;i<n;i++){
            cnums[i] = nums[i] + cnums[i-1];
        }

        long long int ans = 0;
        long long int prod;
        long long int mod = pow(10,9)+7;

        stack<int> st;
        int minval;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<=nums[st.top()]){
                minval = nums[st.top()];
                st.pop();
                prod = cnums[i-1];
                if(!st.empty()){
                    prod -= cnums[st.top()];
                }
                ans = max(ans,prod*minval);
            }
            st.push(i);
        }

        while(!st.empty()){
            minval = nums[st.top()];
            st.pop();
            prod = cnums[n-1];
            if(!st.empty()){
                prod -= cnums[st.top()];
            }
            ans = max(ans,prod*minval);
        }
        
        return ans%mod;
    }
};