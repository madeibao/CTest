
arr = input().split(",")
print(arr)


def result(arr):
    sets = list(map(lambda x:set(x), arr)) # 这一步厉害啊。把各个单词的set求出来
    ans = 0
    for i in range(len(sets)):
        for j in range(i+1, len(sets)):
            if sets[i].isdisjoint(sets[j]): # 这一步就更牛逼了
                ans = max(ans, len(arr[i])*len(arr[j]))
    return ans
print(result(arr))