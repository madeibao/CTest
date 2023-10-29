

# 输入获取
n = int(input())
# n = 50
 
cache = [-1] * 51
cache[0] = 0
cache[1] = 1
cache[2] = 1
cache[3] = 2
 
 
# 算法入口
def recursive(n):
    if cache[n] != -1:
        return cache[n]
 
    cache[n] = recursive(n - 1) + recursive(n - 3)
    return cache[n]
 
 
# 调用算法
print(recursive(n))