class Solution {
    public void merge(int[] nums, int st,int en,int mid){
        ArrayList<Integer> li = new ArrayList<>();
        
        int i = st,j=mid;
        while(i<mid && j<en){
            if(nums[i]<nums[j]){
                li.add(nums[i]);i++;
            }else{
                li.add(nums[j]);j++;
            }
        }
        while(i<mid){
            li.add(nums[i]);i++;
        }
        while(j<en){
            li.add(nums[j]);j++;
        }

        i = st;
        for(int num: li){
            nums[i]=num;i++;
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