import math

m, n = map(int, input().split(" "))
fields = list(map(int, input().split(" ")))
fields.sort(key= lambda x: x)


# m = 5
# n = 7
# fields = [5, 7, 9, 10, 15]
mink = fields[0]
maxk = fields[-1]
# 先考虑边界条件。
if n < m: print(-1)
# k 效率施肥完 fields 所有果林需要的 spend 天数，和指定天数 n 的差距
def spend(k ,n , fields):
    tmp = 0
    for field in fields:
        # 分大于还是小于效能k
        if k >= field : tmp += 1
        else:
            tmp += math.ceil(field/k)
    return tmp - n # 返回 比 n多或者少多少天

ans = -1 # 初始化为-1因为不满足条件也是-1
while mink < maxk: # 左闭右开区间。   
    k = (mink+maxk)//2
    res = spend(k, n, fields)
    print("mink:{}, maxk:{}, k:{}, res:{}".format(mink, maxk,k,res))
    if res > 0: # 注意，这是大于0，不是等于0哈。说明需要比指定天数多，说明k小了，要搞大
        mink = k+1 # 挪动左边界
    
    # elif res == 0:
    #     print(k)
    #     break
    # 综合写下：
    else:
        # res<0, k 取大了要减少注意左闭右开maxk是取不到的
        ans = k # 先记录k
        maxk = k
print(ans)