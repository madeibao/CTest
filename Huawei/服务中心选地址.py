
import math

n = int(input()) # 输入的个数

# 输入区域的左右起点终点
'''
positions = []
for _ in range():
    left, right = input().split(" ")
    positions.append([int(left), int(right)])
'''
# 上面代码可以简写
positions = [list(map(int, input().split(" "))) for _ in range(n)]

# 计算距离
def getDistance(t, positions):
    dis = 0
    for l, r in positions: # 得到某个位置的左右坐标
        if l > t: #当前位置小于左边界
            dis += l-t
        elif r<t:
            dis += t-r
        # 剩下的就是l<t<r就不用算啦
    return dis

def result(n, positions):
    tmp =[]
    for pos in positions:
        tmp.extend(pos) # 得到的序列[1, 2, 3, 4, 10, 20] 注意与append区分。
    # print(tmp)
    tmp.sort()
    minP = float(tmp[0]) # 得到最小值
    maxP = float(tmp[-1]) # 得到最大值。
    while minP < maxP:
        mid = math.ceil((minP + maxP) /2) # Python math.ceil(x) 方法将 x 向上舍入到最接近的整数。 math.floor()向下取整。
        midDis = getDistance(mid, positions)
        midLDis = getDistance(mid-0.5, positions) # mid偏左边
        midRDis = getDistance(mid+0.5, positions) # mid偏右边
        if midDis <= midLDis and midDis <= midRDis:return midDis
        # 都不满足，开始挪动左右指针
        if midDis < midLDis: #这个条件 就是midDis > midRDis 说明右边有小的。
            minP = mid + 0.5 # 往右挪
            continue
        if midDis < midRDis: # #这个条件 就是midDis > midLDis 说明右边有小的。
            maxP = mid - 0.5
    return 0

n = 3
positions = [[1,2], [3,4], [10, 20]]
# 算法调用
print(result(n, positions))