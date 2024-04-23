class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        uniques = set(nums)
        longest = 0

        while uniques:
            left = right = uniques.pop()
            while left-1 in uniques or right +1 in uniques:
                if left -1 in uniques:
                    uniques.remove(left-1)
                    left-=1
                
                if right +1 in uniques:
                    uniques.remove(right+1)
                    right+=1
                
            longest = max(right-left+1, longest)
        return longest

            

            
            