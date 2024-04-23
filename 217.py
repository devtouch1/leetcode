class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        length = len(nums)
        for i in range(length-1):
            if nums[i] == nums[i+1]:
                return True
        return False