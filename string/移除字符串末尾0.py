

class Solution:
    def removeTrailingZeros(self, num: str) -> str:
        return num.rstrip('0')

if __name__=="__main__":
    s = Solution()
    str = "5211314000"
    print(s.removeTrailingZeros(str))