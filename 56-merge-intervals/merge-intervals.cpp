class Solution {
public:
    static bool compareInterval(vector<int>& v1, vector<int>& v2){
        return v1[0] < v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(), compareInterval);
        
        vector<vector<int>> ans;
        vector<int> res(2,0);

        int m = intervals.size();
        
        for(int i=0;i<m;i++){
            res[0] = intervals[i][0];
            res[1] = intervals[i][1];
            for(int j=i+1;j<m;j++){
                if(intervals[j][0]>res[1]){
                    i = j-1; break;
                }
                res[1] = max(intervals[j][1],res[1]);
                i = j;
            }
            ans.push_back(res);
        }
        return ans;
    }
};