

s = input()
k = int(input())

def getNum(s,k):
	nums = list(s)
	nums.sort()

	if(k>len(s)):
		k = len(s)

	res = nums[k-1]
	return s.index(res)


print(getNum(s,k))

# AbCdeFG
# 3

# 输出：
# 5


