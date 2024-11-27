class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        next_great = [-1]*len(nums2)
        stack = []
        d = {}

        for i in range(len(nums2)-1,-1,-1):
            d[nums2[i]] = i
            while stack and nums2[stack[-1]] <= nums2[i]:
                stack.pop()
            if stack:
                next_great[i] = nums2[stack[-1]]
            stack.append(i)
        
        ans = []
        for i in range(len(nums1)):
            ind_nums2 = d[nums1[i]]
            next_greater_el = next_great[ind_nums2]
            ans.append(next_greater_el)
        
        return ans

