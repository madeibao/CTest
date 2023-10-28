import math
seatNum = int(input())
seatOrLeave = eval(input())
print(seatOrLeave)

# seatOrLeave = [1, 1, 1, 1, -4, 1]
# seatOrLeave = [1,1,1,-9,1,1] # 这个用来检查seatNum-1 号走了
def result():
    # 用来表示座位号。
    seat = []
    ans = -1 # 接受的结果 默认值就是异常情况的值。更新了就会变化，没有更新就输出题目想要的异常值嘛。
    for sol in seatOrLeave:
        # onSeat 记录已经使用作为的总数量。
        onSeat = len(seat)
        # 进场，即 sol == 1
        if sol == 1:
            if onSeat == 0:
            # 如果还没人坐，则进来的这个人坐 0 号座位
                ans = 0
                seat.append(ans)
            elif onSeat == 1:
                # 如果只有一个人在坐，那么这个人肯定坐在 0 号位，则下一个人肯定坐到 seatNum-1 号位
                ans = seatNum-1
                seat.append(ans)
            else:
                '''
                如果有两个座位或以上被占用，则我们应该让下一个人坐在最大区间的中间位置
                我们只需要求出最大区间，然后记录该区间的起始位置start，以及区间长度一半长度maxDis，即可得出下一个人的最佳座位号
                '''
                maxDis = 0
                start = -1
                # seat表示坐好人的位置，比如现在坐好了0,4,9 题目说了0干不掉所以，0-4,4-9
                for i in range(1, len(seat)):
                    p = seat[i-1] # seat[0] 永远是0
                    c = seat[i]
                    # 如果 p 座位和 c 座位紧邻，则中间没有空位，因此直接下一个区间
                    if c == p+1:
                        continue
                    dis = math.ceil((c - p -1)/2) # 向上取整数。这个数加上取值的一半的向上取整。
                    if dis > maxDis:# 要大于才更新嘛。<=不更新，因为题目说了是区间相同取最小。
                        maxDis = dis
                        start = p
                # seat 的 0 号位的人肯定不会走（题目说的），但是 seatNum-1 号的人可能会走，因此我们还需要考虑 seat.at(-1) ~ seatNum - 1 区间
                # 假设seatNum-1号走了，就要判断seat[-1]与seatNum - 1的距离啊
                brand_dis = seatNum - 1 - seat[-1] #这里也是坑啊
                # ，这里就不用除以2了。相当于把这个人直接放到seatNum - 1看他的距离与上面循环的maxDis哪个大。
                if brand_dis > maxDis: # 如果大了
                    maxDis = brand_dis#就更新maxDis
                    start = seat[-1] # 这样就start = seat[-1] 然后执行下面的start+maxDis不就是seatNum-1号嘛
                ans = start+maxDis
                if ans !=-1: #更新了。
                    seat.append(ans)
                    seat.sort()

        else:
            # 出场
            if -sol in seat:
                idx = seat.index(-sol)
                seat.pop(idx)
    return ans


print(result())



10
[1,1,1,1,-4,1]
[1, 1, 1, 1, -4, 1]       
5