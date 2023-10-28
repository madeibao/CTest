# 输入获取
n = int(input())
positions = list(map(int, input().split()))
# 7
# 1 5 3 6 10 7 13
# 3
m = int(input())
print(n, m)
print(positions)



def check(mid):
    cnt = 1
    curPos = positions[0] #初始化当前位置
    for i in range(1, n):
        if positions[i]-curPos >= mid:
            cnt += 1
            # 更新当前位置
            curPos = positions[i]
    return cnt >= m # 不要把m和mid混起来。
def result():
    # 上来位置先排序
    positions.sort()
    # 初始化左右边界
    l, r = 1, positions[-1]-positions[0]
    ans = 0
    while l <= r:
        mid = (l+r)//2
        if check(mid):
            ans = mid
            l = mid + 1
        else:
            r = mid - 1 # 这里别写反了。
    return ans


print(result())