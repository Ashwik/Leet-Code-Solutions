class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        grid = [1] * n

        for i in range(1,m):
            for j in range(1,n):
                grid[j] += grid[j-1]

        return grid[n-1]
        