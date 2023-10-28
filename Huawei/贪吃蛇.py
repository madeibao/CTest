

op = input().split() # 操作
'''
D G G
3 3
F F F
F F H
E F E
'''
n, m = map(int, input().split()) # n行， m列
matrix = [input().split() for i in range(n)]
print(op)
print(n, m)
print(matrix)

def go(i, j, snake, dir):
    # [r,c]是当前蛇头位置，[i,j]是上一次蛇头位置
    r, c = i, j # r行，c列。
    if dir == "U":
        r -= 1
    elif dir == "D":
        r += 1
    elif dir == "L":
        c -= 1
    elif dir == "R":
        c += 1
    # 越界判断。游戏结束，返回snake的长度。
    if r<0 or r>=n or c<0 or c>=m:
        return len(snake)
    else:
        # 没越界 
        # 蛇头是空地
        if matrix[r][c] == "E":
            matrix[r][c] = "H"
            snake.insert(0, [r,c])
            x, y = snake.pop()
            matrix[x][y] = "E"
        # 如果蛇头的位置是食物，把他吃了，然后增加长度。
        elif matrix[r][c] == "F":
            snake.insert(0, [r,c])
            matrix[r][c] = "H"
        else:
            # 如果吃到自己的身体，游戏结束
            return len(snake)
    return 0 #都没干到return ，就return 0 ，表示可以进行下一步操作。
            

def result():
    snake = []
    # 找蛇头的位置
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == "H":
                snake.append([i, j])
    # 蛇头默认移动向左一步
    dir = "L"
    for o in op:
        if o == "G":
            # 如果为G，则表示验证direction方向移动一格
            x, y = snake[0]
            res = go(x, y, snake, dir) # 移动
            if res > 0:
                return res
        else:
            dir = o
    return len(snake)


print(result())



D G G
3 3
F F F
F F H
E F E
['D', 'G', 'G']
3 3
[['F', 'F', 'F'], ['F', 'F', 'H'], ['E', 'F', 'E']]
1