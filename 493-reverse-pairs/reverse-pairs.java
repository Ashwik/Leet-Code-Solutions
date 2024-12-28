class Solution {
    public void merge(int[] nums, int st,int en,int mid){
        int arr[] = new int[en-st];
        int k =0;
        int i = st,j=mid;
        while(i<mid && j<en){
            if(nums[i]<nums[j]){
                arr[k++] = nums[i++];
            }else{
                arr[k++] = nums[j++];
            }
        }
        while(i<mid){
           arr[k++] = nums[i++];
        }
        while(j<en){
           arr[k++] = nums[j++];
        }

        i = st;
        for(j=0;j<arr.length;){
            nums[i++]=arr[j++];
        }
        return;
    }

    public void mergesort(int[] nums,int st,int en,int[] ans){
        if(st==en-1){
            return;
        }
        int mid = (st+en)/2;
        mergesort(nums,st,mid,ans);
        mergesort(nums,mid,en,ans);

        for(int i=st,j=mid;i<mid&&j<en;){
            if(nums[i]/2.0 > nums[j]){
                ans[0] += (mid-i);
                j++;
            }else{
                i++;
            }
        }

        merge(nums,st,en,mid);
    }

    public int reversePairs(int[] nums) {
        int[] ans = new int[1];
        mergesort(nums,0,nums.length,ans);
        return ans[0];
    }
}