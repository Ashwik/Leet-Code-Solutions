class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        
        def subsets(ind):
            if ind == len(nums):
                return
                    

            for i in range(ind,len(nums)):
                if i > ind and nums[i] == nums[i-1]:
                    continue
                cur_ans.append(nums[i])
                main_ans.append(cur_ans[:])
                subsets(i+1)
                cur_ans.pop()
        
        main_ans = [[]]
        cur_ans = []
        nums.sort()
        subsets(0)

        return main_ans