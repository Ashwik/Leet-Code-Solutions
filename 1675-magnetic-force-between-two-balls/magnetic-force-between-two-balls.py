class Solution:

            

    def maxDistance(self, position: List[int], m: int) -> int:
        

        res = -1
        position.sort()
        n = len(position)
        maxpos = position[-1] - position[0]
        minpos = 0
        # for i in range(1,len(position)):
        #     minpos = min(minpos,position[i]-position[i-1])        
        

        def is_assign_possible(midposition):
            
            allocatedballs = 1
            prevpos = position[0]
            for i in range(1,n):
                if position[i]-prevpos >= midposition:
                    allocatedballs = allocatedballs + 1
                    prevpos = position[i]
            
            if allocatedballs < m:
                return False
            
            return True

        while(minpos<=maxpos):
            mid = (minpos+maxpos)//2
            #print("minpos: ",minpos," mid: ",mid, " max pos: ",maxpos)
            if is_assign_possible(mid):
                res = mid
                #print(res)
                minpos = mid+1
            else:
                maxpos = mid-1
        
        return res