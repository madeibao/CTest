# 输入获取
n, m = map(int, input().split())
 
suit = []
for _ in range(n):
    x, y = map(int, input().split())
    suit.append(x + y)
 
 
# 算法入口
def getResult():
    suit.sort()
 
    count = 1  # 第1个合适的菜必吃
    pre = 0
 
    for i in range(1, len(suit)):
        if suit[i] >= suit[pre] + m:
            # 如果想要捞本次合适的菜，则必须要与上次捞菜的时间差大于等于m，
            # 注意这里是suit[pre] + m ，而不是suit[i-1] + m
            count += 1
            # 如果本次捞了菜，则更新缓存本次捞菜的时间点
            pre = i
 
    return count
 
 
# 调用算法
print(getResult())



2 1
1 2
2 1

#--------------------
1

