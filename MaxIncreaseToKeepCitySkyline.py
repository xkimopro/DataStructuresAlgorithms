# Link -> https://leetcode.com/problems/max-increase-to-keep-city-skyline/

import math

class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        iSkyline = []
        n = len(grid)
        for row in grid:
            max = float('-inf')
            for i in row:
                if i > max:
                    max = i
            iSkyline.append(max)
        jSkyline = []       
        for j in range(n):
            max = float('-inf') 
            for i in range(n):
                if grid[i][j] > max:
                    max = grid[i][j]
            jSkyline.append(max)
            
        incr = 0
        for i in range(n):
            for j in range(n):
                maxHeight = min(iSkyline[i], jSkyline[j])
                incr += maxHeight - grid[i][j]
            
        return incr