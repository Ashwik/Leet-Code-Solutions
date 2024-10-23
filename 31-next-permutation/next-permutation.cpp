class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int i = n-1;
        for(;i>0;i--){
            if(arr[i]>arr[i-1]){
                for(int j=n-1;j>=i;j--){
                    if(arr[j]>arr[i-1]){
                        swap(arr[j],arr[i-1]);
                        break;
                    }
                }
                sort(arr.begin()+i, arr.end());
                break;
            }
        }
        if(i==0){
            sort(arr.begin(), arr.end());
        }
    }
};