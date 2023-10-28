

def help(s1, s2):
    if s1[-1]!=s2[-1]:
        return "" # 如果尾字符不同，则没有公共后缀 
    # 最长公共后缀的长度上限是：两个字符串中较短的那个的长度值
    maxLen = min(len(s1), len(s2))
    for i in range(-2, -maxLen-1, -1):
        '''
        画图解决，倒数第一个为-1，那么第一个为-1-(len(s)-1). 比长度只有1，最后一个，和第一个都是-1，长度为2，第一个就是-2 = -1-(2-1)
        也就是说-len(s)(这个也对应下面的return s1[-maxLen:]) 
        然后因为range右边是开区间，所以呢要再往前推进1，所以就是-len(s)-1
        '''
        # 从倒数第二个开始，然后到第一个，那就是maxLen-1

        if s1[i] != s2[i]:
            return s1[i+1:]
    # 如果比较完了，都没有发现对应位不同字符，则说明，两个字符串中较短者本身就是最长公共后缀
    return s1[-maxLen:]
def result(strs):
    # 假设第0个字符串就是最长公共后缀
    suffix = strs[0]
    for i in range(1, len(strs)):
        # 逐个的判断
        suffix = help(suffix, strs[i])
        if suffix == "":
            return "@Zero"
    return suffix

arr = list(input().split(","))
# strs = ["abc","bc","c"]
print(result(arr))