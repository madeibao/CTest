
2
3 5
1 0 1 0 0
0 1 1 0 1
0 0 1 0 1

// 第一个是步长
// 3行五列
// 然后是对应的矩阵。

def demo(arr,s,i,j):
    if i<0 or j<0 or i>=len(arr) or j>=len(arr[0]) or arr[i][j]==0:
        return False
    if i == len(arr)-1 and j == len(arr[0])-1:
        return True

    arr[i][j] = 0
    return demo(arr, s, i-s, j) or demo(arr, s, i+s, j) or demo(arr, s, i, j-s) or demo(arr, s, i, j+s)




s = int(input())
row, col = list(map(int,input().split()))
arr = [[0 for _ in range(col)] for _ in range(row)]
for i in range(row):
    arr[i] = list(map(int, input().split()))


if demo(arr, s, 0, 0):
    print(1)
else:
    print(0)


