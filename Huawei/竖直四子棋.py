c, r = map(int, input().split()) # c列， r行
cols = list(map(int, input().split()))
'''
5 5
1 1 2 2 3 3 4 4
'''
print(c, r)
print(cols)


# 构造棋盘，注意棋盘长宽都+1了，方便后面棋子获取
matrix = [[0]*(c+1) for i in range(r+1)]
# 偏移量 上，左，左上，左下 偏移量
directs = ((-1,0), (0,-1), (-1,-1), (-1,1))
def isFour(x, y, player):
    for dirx, diry in directs:
        long = 1
        # 向着某个方向延申判断是否存在相同子
        x1, y1 = x, y # 复制一份。
        while True:
            x1 += dirx
            y1 += diry
            # 边界条件判定。而且是该人下的棋 注意这里从1开始啊。
            if r>=x1>=1 and c>=y1>=1 and matrix[x1][y1] == player:
                long+=1
            else:
                break # 循环结束
        # 向着上面方向的反方向延申判断是否存在相同子（两个相反方向其实处于一条线上）
        x2, y2= x, y # 复制一份。 为啥不八个方向一起呢。
        while True:
            x2 -= dirx
            y2 -= diry
            # 边界条件判定。而且是该人下的棋 注意这里从1开始啊。
            if r>=x2>=1 and c>=y2>=1 and matrix[x2][y2] == player:
                long+=1
            else:
                break # 循环结束
        # 长度为4的判断
        if long >= 4:
            return True
    # 循环完了
    return False

def result():
    for i in range(len(cols)):
        # 这里i对应第几步，由于题目是从第1步开始算，而这里 i 从0开始算，因此最终返回要i+1
        # 出错判断 非法落子步骤有两种，一是列的编号超过棋盘范围，二是在一个已经落满子的列上落子。
        if cols[i] <1 or cols[i]>c:
            return f"{i+1},error"
        # player落子颜色：1代表红色，2代表蓝色
        player = 1 if i%2 == 0 else 2
        # 开始落子
        x, y = r, cols[i]
        while matrix[x][y] >0:
            # 如果当前列底部有棋子，则需要往上查找
            x -= 1
            if x<1:
                return f"{i+1},error" # 如果当前列已经放满棋子，就报错
        matrix[x][y] = player # 如果单签列底部没有放满，则可以放入
        # i>6,就是第7步之后才有可能产生4连击
        if i >= 6 and isFour(x, y, player):
            return f"{i+1},{'red' if player == 1 else 'blue'}"
    # 双方平局
    return "0,draw"

print(result())