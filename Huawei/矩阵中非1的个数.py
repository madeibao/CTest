
m, n = map(int, input().split()) # m是行，n是列
arr = [list(map(int, input().split())) for i in range(m)]

matrix = [[0, 0, 0, 0], [0, 2, 2, 2], [0, 2, 0, 0], [0, 2, 0, 0]]
matrix[0][0] = 1
def result(m,n,matrix):
    matrix[0][0]=1
    directs = ((1,0),(-1,0),(0,-1),(0,1))
    queue = [[0, 0]]
    count = 1
    while len(queue)>0:
        x, y = queue.pop(0)
        # print(x,y)
        for dirx, diry in directs:
            newX = x + dirx
            newY = y + diry
            if m>newX>=0 and n>newY>=0 and matrix[newX][newY] == 0:
                matrix[newX][newY] = 1
                count += 1
                queue.append([newX,newY])
    return m*n-count

print(result(m,n,matrix))
