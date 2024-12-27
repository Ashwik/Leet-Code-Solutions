class Solution {

    public void findnextgreaterelement(List<Integer> nums,int target){
        int st = 0,en=nums.size();
        int mid;

        while(st<en){
            mid = (st+en)/2;
            int num = nums.get(mid);
            if(num==target){
                return;
            }else if(num<target){
                st = mid+1;
            }else{
                en = mid;
            }
        }
        nums.set(st,target);
        return;
    }

    public int lengthOfLIS(int[] nums) {
        List<Integer> st = new ArrayList<>();
        st.add(nums[0]);
        int ans = 1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]>st.get(st.size()-1)){
                st.add(nums[i]);
            }else{
                findnextgreaterelement(st,nums[i]);
            }
        }
        return st.size();
    }
}