class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        sol = [1]*n
        pre = 1
        post = 1
        for i in range(n):
            sol[i] *= pre
            pre = pre*nums[i]
            sol[n-i-1] *= post
            post = post*nums[n-i-1]
        return sol