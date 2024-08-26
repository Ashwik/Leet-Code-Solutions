class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        heights.push_back(0);
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        int height;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                height = heights[st.top()];
                st.pop();
                int leftind = st.empty()? -1:st.top();
                int width = i-1-leftind;
                ans = max(ans,height*width);
            }
            st.push(i);
        }

        
        return ans;
    }
};