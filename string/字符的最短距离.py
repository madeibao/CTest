
from typing import List

class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:

        a,b=[],[]

        for i in range(len(s)):
            if s[i]==c:
                a.append(i)


        for i in range(len(s)):

            ans=float('inf')
            if s[i]!=c:
                for j in a:
                    ans=min(ans,abs(i-j))
                b.append(ans)
            elif s[i]==c:

                b.append(0)

        return b


if __name__ == '__main__':
    s = Solution()
    str = "loveleetcode";
    c = "e"
    res = s.shortestToChar(str, c)
    for i in res:
        print(i)