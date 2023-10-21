


class Solution:
    def repeatedCharacter(self, s: str) -> str:
        occ = set()
        for c in s:
            if c not in occ:
                occ.add(c)
            else:
                return c
        return ''


if __name__ == "__main__":
    str2 = "abccbaacz"
    s2 = Solution()
    print(s2.repeatedCharacter(str2))