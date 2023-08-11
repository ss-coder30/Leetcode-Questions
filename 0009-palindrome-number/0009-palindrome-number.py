class Solution:
    def isPalindrome(self, x: int) -> bool:
        
        originalNum = x
        
        revNum = 0
        
        if(x < 0):
            return False
        
        while(x != 0):
            lastDigit = x%10
            x = x//10
            revNum = (revNum * 10)+lastDigit
            
        if(revNum == originalNum):
            return True
        else:
            return False