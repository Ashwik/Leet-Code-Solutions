class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> right(height.size(),0);

        stack<int> st;
        int num = 0;
        for(int i=height.size()-1;i>=0;i--){
            right[i] = num;
            num = max(right[i],height[i]);
        }

        int ans = 0;
        int left = 0;
        for(int i=0;i<height.size()-1;i++){
            ans += max(min(left,right[i]) - height[i],0);
            left = max(left,height[i]);
        }
        return ans;
    }
};