class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> li = new ArrayList<>();
        int[] count = new int[2];
        int[] arr = new int[2];
        arr[0]=nums[0];
        arr[1]=nums[0];
        count[0]=1;
        
        for(int i=1;i<nums.length;i++){
            if(nums[i]==arr[0]){
                count[0]++;
            }else if(nums[i]==arr[1]){
                count[1]++;
            }else if(count[0]==0){
               arr[0]=nums[i];
               count[0]++;
            }else if(count[1]==0){
                arr[1]=nums[i];
                count[1]++;
            }else{
                count[0]--;
                count[1]--;
            }
        }
        count[0]=0;
        count[1]=0;
        for(int i=0;i<nums.length;i++){
            if(arr[0]==nums[i]){
                count[0]++;
            }else if(arr[1]==nums[i]){
                count[1]++;
            }
        }
        int k = nums.length/3;
        if(count[0]>k){
            li.add(arr[0]);
        }
        if(count[1]>k){
            li.add(arr[1]);
        }
        return li;
    }
}