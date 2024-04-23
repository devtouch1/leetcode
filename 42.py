class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        left = 0
        right = len(height) - 1
        max_left = height[left]
        max_right = height[right]
        areas = 0
        while left <= right:
            if max_left < max_right:
                preArea = max_left - height[left]
                area = preArea if preArea > 0 else 0
                areas += area
                max_left = max(max_left, height[left])
                left += 1
            else:
                preArea = max_right - height[right]
                area = preArea if preArea > 0 else 0
                areas += area
                max_right = max(max_right, height[right])
                right -= 1
        return areas