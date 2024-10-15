class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        n = len(nums)
        a = 0 
        b = 0

        for i in range(0,n):
            if(nums[i]==0):
                a = a+1
            elif(nums[i]==1):
                b = b+1
        
        for i in range(0,n):
            if(a>0):
                nums[i] = 0
                a = a - 1
            elif(b>0):
                nums[i] = 1
                b = b-1
            else:
                nums[i] = 2
        