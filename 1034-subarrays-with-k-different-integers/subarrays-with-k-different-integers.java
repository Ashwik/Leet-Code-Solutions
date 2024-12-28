class Solution {
    public int findArraysWithAtmostKDistinct(int[] nums,int k){
        HashMap<Integer,Integer> mp= new HashMap<>();
        int ans = 0;
        int i=0,j=0;
        for(i=0,j=0;i<nums.length;i++){
            mp.put(nums[i],mp.containsKey(nums[i]) ? mp.get(nums[i])+1 : 1);
            while(mp.size()>k){
                mp.put(nums[j],mp.get(nums[j])-1);
                if(mp.get(nums[j])==0){
                    mp.remove(nums[j]);
                }
                j++;
            }
            ans += i-j+1;
        }
        return ans;
    }

    public int subarraysWithKDistinct(int[] nums, int k) {
        return findArraysWithAtmostKDistinct(nums,k) - findArraysWithAtmostKDistinct(nums,k-1);
    }
}