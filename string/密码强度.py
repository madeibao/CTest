



class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        if len(password) < 8: return False
        b, s, n, t = False, False, False, False
        for i in range(len(password)):
            if password[i].islower(): s = True
            elif password[i].isupper(): b = True
            elif password[i].isdigit(): n = True
            elif password[i] in "!@#$%^&*()-+": t = True
            if i != 0 and password[i] == password[i-1]: return False
        return b and s and n and t


if __name__ == "__main__":

	s2 = Solution()
	password = "IloveLe3tcode!"
	print(s2.strongPasswordCheckerII(password))
	
