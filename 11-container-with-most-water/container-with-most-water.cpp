class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int res = 0;
        int area;
        for(int i=0,j=height.size()-1;i<j;){
            if(height[i]<=height[j]){
                area = height[i]*(j-i);
                i++;
            }else{
                area = height[j]*(j-i);
                j--;
            }
            res = max(res, area);
        }
        return res;

    }
};