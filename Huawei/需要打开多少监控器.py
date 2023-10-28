

m, n = map(int, input().split())
arr = [list(map(int, input().split())) for i in range(m)]
print(m, n)
print(arr)


directs = ((1,0), (-1,0), (0, 1), (0,-1))
def result():
    cnt = 0
    for i in range(m):
        for j in range(n):
            if arr[i][j] ==1:
                cnt += 1
                continue
            # 只要一个方向上为1，他就要打开监控。
            for dirx, diry in directs:
                newX = i + dirx
                newY = j + diry
                if m>newX>=0 and n>newY>=0 and arr[newX][newY] == 1:
                    cnt += 1
                    break
    return cnt

print(result())