class Solution {
public:

    void merge(vector<int>& nums,int st,int en){
        int mid = (st+en)/2;
        vector<int> temp(en-st,0);
        int i = st;
        int j = mid;
        int k=0;
        while(i<mid && j<en){
            if(nums[i]<nums[j]){
                temp[k++] = nums[i++];
            }else{
                temp[k++] = nums[j++];
            }
        }

        while(i<mid){
            temp[k++] = nums[i++];
        }

        while(j<en){
            temp[k++] = nums[j++];
        }
        i = st;
        k = 0;

        while(i<en){
            nums[i++] = temp[k++];
        }
    }

    int mergeSort(vector<int>& nums,int st,int en){
        
        if(st>=(en-1)){return 0;}
        int mid =(st+en)/2;

        int ans = mergeSort(nums,st,mid) + mergeSort(nums,mid,en);

        for(int i=st,j=mid;i<mid;i++){
            while(j<en && nums[i]/2.0 > nums[j]){
                j++;
            }
            ans += j-mid;
        }
        merge(nums,st,en);
        return ans;
    }

    int reversePairs(vector<int>& nums) {
        int ans = mergeSort(nums,0,nums.size());
        return ans;
    }
};