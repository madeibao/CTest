


n = int(input())
alpha = input().split()
res = []
loc = ''


def combine(x, y):
    global res
    if len(x) == 0:  # 停止条件
        res.append(y)  # 输出结果
        return 0
    else:
        l_x = len(x)
        for i in range(l_x):  # 常见深度优先算法
            a = x[i]  # 当前数
            b = x[:i] + x[i + 1:]  # 剩下的放入下次循环中
            combine(b, y + a)  # 为不影响其他组合，变量计算需要在函数中进行
        return


combine(alpha, loc)
res_new = sorted(list(set(res)))
for j in res_new:
    print(j)
