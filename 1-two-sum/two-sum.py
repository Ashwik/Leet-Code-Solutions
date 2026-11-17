class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        d:dict[int,int] = {}
        li:list[int] = []
        for i in range(0,len(nums)):
            num = target - nums[i];
            if num in d.keys():
                li.append(d[num])
                li.append(i)
                break
            d[nums[i]] = i
        
        return li
            
        