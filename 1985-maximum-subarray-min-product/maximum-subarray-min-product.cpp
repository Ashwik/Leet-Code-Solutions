class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(nums.size(),-1);
        vector<int> right(nums.size(),n-1);

        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<=nums[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                left[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]<nums[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                right[i] = st.top()-1;
            }
            st.push(i);
        }

        vector<long long int> cnums(n);
        cnums[0] = nums[0];
        for(int i=1;i<n;i++){
            cnums[i] = nums[i] + cnums[i-1];
        }

        long long int ans = 0;
        long long int prod;
        long long int mod = pow(10,9)+7;

        for(int i=0;i<nums.size();i++){
            prod = cnums[right[i]];
            if(left[i]!=-1){
                prod -= cnums[left[i]];
            }
            prod = (prod*nums[i]);
            ans = max(ans,prod);
        }
        return ans%mod;
    }
};