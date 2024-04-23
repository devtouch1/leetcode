class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        l,r = 0, n-1
        maxArea = 0
        while l<r:
            area = (r-l)*min(height[l],height[r])
            maxArea = max(maxArea,area)
            if height[l]<height[r]:
                l+=1
            else:
                r-=1
        
        return maxArea