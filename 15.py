class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        le = len(nums)
        res = []
        i=0
        while i<le-2:
            a = nums[i]
            l = i+1
            r = le-1
            while l<r:
                soma = a+nums[l]+nums[r]
                if soma < 0:
                    l+=1
                elif soma > 0:
                    r-=1
                else:
                    res.append([a, nums[l], nums[r]])
                    while l<r and nums[l+1]==nums[l]:
                        l+=1
                    while l<r and nums[r-1]==nums[r]:
                        r-=1
                    l+=1
                    r-=1
            while nums[i+1]==nums[i] and i<le-2:
                i+=1
            i+=1
        return res

                