




class Solution:
    def countSubstrings(self, s: str) -> int:
        cnt = 0
        for i in range(len(s)):
            for j in range(i+1, len(s)+1):   # range函数前面是闭区间，后面是开区间。
                if s[i:j] == s[i:j][::-1]:
                    cnt += 1
        return cnt


if __name__ == "__main__":
    s = "abc"
    s2 = Solution()
    print(s2.countSubstrings(s));