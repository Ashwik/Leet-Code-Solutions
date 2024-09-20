class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> v; 
        vector<int> facn;
        facn.push_back(1);

        for(int i=1;i<=n;i++){
            v.push_back(i);
            facn.push_back(i*facn.back());
        }

        int num = n-1;
        int index,reminder;
        string ans="";

        
        for(int i=0;i<n;i++){
            index = (k-1)/facn[num];
            reminder = (k-1)%facn[num];
            ans += to_string(v[index]);
            v.erase(v.begin()+index);
            num--;
            k = reminder+1;
        }
        return ans;
    }
};