class Solution:

    def is_assign_possible(self, position, totalballs, midposition):
        
        allocatedballs = 1
        prevpos = position[0]
        for i in range(1,len(position)):
            if position[i]-prevpos >= midposition:
                allocatedballs = allocatedballs + 1
                prevpos = position[i]
        
        if allocatedballs < totalballs:
            return False
        
        return True
            

    def maxDistance(self, position: List[int], m: int) -> int:
        

        res = -1
        position.sort()
        maxpos = position[-1] - position[0]
        minpos = maxpos
        for i in range(1,len(position)):
            minpos = min(minpos,position[i]-position[i-1])        
        

        while(minpos<=maxpos):
            mid = (minpos+maxpos)//2
            #print("minpos: ",minpos," mid: ",mid, " max pos: ",maxpos)
            if self.is_assign_possible(position,m,mid):
                res = mid
                #print(res)
                minpos = mid+1
            else:
                maxpos = mid-1
        
        return res