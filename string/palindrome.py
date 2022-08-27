


##############################------------------------------------------------------------------------------
#验证回文字符串


class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        n = len(s)
        i = 0
        j = n-1

        while i < j:
            if s[i].isalnum() == False:
                i += 1
                continue
            if s[j].isalnum() == False:
                j -= 1
                continue
            if s[i].lower() != s[j].lower():
                return False
            i += 1
            j -= 1
        return True


if __name__ == '__main__':
	s = Solution()
	str =  "A man, a plan, a canal: Panama"
	print(s.isPalindrome(str))