class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        left = 0
        right = len(s)-1
        while left < right:
            cleft = s[left]
            cright = s[right]
            if cleft.isalnum() == False:
                left+=1
                continue
            elif cright.isalnum() == False:
                right-=1
                continue

            cleft = cleft.lower()
            cright = cright.lower()
            
            if cleft != cright:
                return False
            
            left+=1
            right-=1
        
        return True
            

        
        