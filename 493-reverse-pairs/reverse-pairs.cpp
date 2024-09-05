class Solution {
public:

    void merge(vector<int>&nums,int st,int mid,int en){

        int i = st,j=mid;
        int v[en-st];
        int k = 0;
        for(;i<mid&&j<en;){
            if(nums[i]<=nums[j]){
                v[k] = nums[i];k++;
                i++;
            }else{
                v[k] = nums[j];k++;
                j++;
            }

        }
        while(i<mid){
           v[k] = nums[i];k++;
            i++;
        }

        while(j<en){
            v[k] = nums[j];k++;
            j++;
        }
        i = st;
        for( k=0;k<en-st;k++){
            nums[i] = v[k];i++;
        }


    }

    int  mergesort(vector<int>&nums ,int st,int en){

        if(st+1==en || st==en){return 0;}
        int mid = (st+en)/2;
        int ans = mergesort(nums,st,mid) + mergesort(nums,mid,en);

        for(int i=st,j=mid;i<mid;i++){
            while(j<en&&nums[i]/2.0>nums[j]){
                j++;
            }
            ans += j-mid;
        }

        merge(nums,st,mid,en);
        return ans;
    }

    int reversePairs(vector<int>& nums) {
        int ans;
        ans = mergesort(nums,0,nums.size());
        return ans;
    }
};