作者：厚德载物
链接：https://zhuanlan.zhihu.com/p/647319337
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

directs = ((1,0), (-1,0), (0,1), (0,-1))
def result():
    # 记录每个图形的边长
    ans = []
    # 构造矩阵
    matrix = [[0] *64 for i in range(64)]
    # 填充数字
    for line in lines:
        # 第一个数字标记的是单元格填充啥数字
        num = line[0]
        # 后面的是坐标啊,x,y,所以步长为2
        for i in range(1, len(line), 2):
            x = line[i]
            y = line[i+1]
            matrix[x][y] = num # 对应的坐标填充对应的数字
    for line in lines:
        num = line[0]
        p = 0 # 周长
        for i in range(1, len(line), 2):
            x = line[i]
            y = line[i+1]
            # print(x, y) # 在line里的坐标，就相当于实心货，
            # 然后往四方搜，1.越界了，周长要加1
            # 没有越界，只要那个方格的值跟自己的不相等，周长就要加1.这个想法很好啊。
            for dirx, diry in directs:
                newX = x + dirx
                newY = y + diry
                # 改点向四周扫一圈没有越界
                if 64>newX>=0 and 64>newY>=0:
                    if matrix[newX][newY] != num:
                        # 说明没有扫到填充物
                        p += 1
                # 碰到边界了，也会围起来。所以也要加1，这里是本题的关键。
                else:
                    # 越界了
                    p += 1
        ans.append(p)
    return " ".join(map(str, ans))


if __name__=="__main__":

    n = int(input()) # 输入n行数字
    lines = [list(map(int, input().split())) for i in range(n)]
    print(lines)
    print(result())


# 2
# 1 1 3 2 2 2 3 2 4 3 2 3 3 3 4 4 1 4 2 4 3 4 4 5 2 5 3
# 2 3 7 3 8 4 5 4 6  4 7 4 8 5 4 5 5 5 6 5 7 5 8 6 4 6 5 6 6 6 7 6 8 7 4 7 5 7 6 7 7 7 8
