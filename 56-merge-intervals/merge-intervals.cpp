class Solution {
public:
    static bool compareInterval(vector<int>& v1, vector<int>& v2){
        return v1[0] < v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(), compareInterval);
        
        vector<vector<int>> ans;
        int res1=0,res2=0;

        int m = intervals.size();
        
        for(int i=0;i<m;i++){
            res1 = intervals[i][0];
            res2 = intervals[i][1];
            for(int j=i+1;j<m;j++){
                if(intervals[j][0]>res2){
                    i = j-1; break;
                }
                res2 = max(intervals[j][1],res2);
                i = j;
            }
            ans.push_back({res1,res2});
        }
        return ans;
    }
};