

n, m = map(int, input().split()) # n行 m列
matrix = [list(input().split(",")) for i in range(n)]
print(n, m)
print(matrix)

def result(matrix):
    ans = 0
    # 只用开4个方向。
    directs = ((0,1),(1,0),(1,1),(1,-1))
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == "M":
                for dirx, diry in directs:
                    oldX = i-dirx
                    oldY = j-diry
                    if n>oldX>=0 and m>oldY>=0 and matrix[oldX][oldY] == "M":
                        # 这种情况下找过了，就不用再找了。所以continue
                        continue
                    # 没找过
                    length = 1
                    newX = i+dirx
                    newY = j+diry
                    # 这么一梭哈，来个while循环，在一个方向，一个劲的搜，while厉害啊。不服不行啊
                    while n>newX>=0 and m>newY>=0 and matrix[newX][newY] == "M":
                        length += 1
                        newX += dirx
                        newY += diry
                    # while到底不了。要更新ans
                    ans = max(ans,length)
    return ans

print(result(matrix))



# 3 4
# F,M,M,F 
# F,M,M,F
# F,F,F,M