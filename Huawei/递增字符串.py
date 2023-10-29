

# 递增字符串
from collections import Counter
s = input()
# s = 'AABBA'
def result(s):
    n = len(s)
    A = Counter(s)["A"]
    # print(A)
    if A ==0 or A==n:
        return 0
    # 这里 dp 缓存的是分界线左边（含分界线位置）一共有多少个 A，这里本来使用dp 数组的，
    # 但是 str 的长度太长了，用 dp 数组会爆内存
    dp = 0
    if s[0] == "A": # 0 索引位置为分界线的话
        dp = 1
    ans = test(0, dp, A-dp)
    for i in range(1, n):
        if s[i] == "A":
            dp += 1
        ans = min(ans, test(i, dp, A-dp))
    return ans
# # brandIdx 表示分界线，即[0,brandIdx]闭区间内理论上都是 A，而(brandIdx，str.length)开区间内理论上都是 B
'''
brandIdx + 1 表示[0,brandIdx]闭区间内理论上应该都多少个 A
brand_LM_A 表示[0,brandIdx]闭区间内实际上有多少个 A
brandIdx + 1 - brand_LM_A 表示[0,brandIdx]闭区间内应该做多少次修改，让该区间全是 A
brand_R_A 表示(brandIdx，str.length)开区间内应该做多少次修改，让该区间全是B
'''
def test(brandIdx, brand_LM_A, brand_R_A):
    return brandIdx+1-brand_LM_A+brand_R_A

print(result(s))