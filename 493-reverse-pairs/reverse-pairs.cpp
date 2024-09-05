class Solution {
public:

    int ans;
    void merge(vector<int>& nums,int st,int en){
        int mid = (st+en)/2;
        vector<int> temp(en-st,0);
        int i = st;
        int j = mid;
        int k=0;
        while(i<mid && j<en){
            if(nums[i]<nums[j]){
                temp[k] = nums[i];
                i++;
            }else{
                temp[k] = nums[j];
                j++;
            }
            k++;
        }

        while(i<mid){
            temp[k] = nums[i];
            i++;k++;
        }

        while(j<en){
            temp[k] = nums[j];
            j++;k++;
        }
        i = st;
        k = 0;

        for(;i<en;i++,k++){
            nums[i] = temp[k];
        }


    }

    void mergeSort(vector<int>& nums,int st,int en){
        
        if(st>=(en-1)){return;}
        //cout<<st<<" "<<en<<endl;
        int mid =(st+en)/2;

        mergeSort(nums,st,mid);
        mergeSort(nums,mid,en);

        for(int i=st,j=mid;i<mid;i++){
            while(j<en && nums[i]/2.0 > nums[j]){
                j++;
            }
            ans += j-mid;
        }

        merge(nums,st,en);
    }


    int reversePairs(vector<int>& nums) {
        ans = 0;
        mergeSort(nums,0,nums.size());
        // for(int i=0;i<nums.size();i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        return ans;
    }
};