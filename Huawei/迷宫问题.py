

# n, m = map(int, input().split()) # n行，m列
# matrix = [list(map(int, input().split())) for i in range(n)]
# print(n, m)
# print(matrix)

n,m = 5,5
matrix = [[0, 1, 0, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 1, 0]]
directs = ((-1,0), (1,0), (0,-1), (0,1))
def dfs(i, j, path, ans):
    if i==n-1 and j==m-1: #到目的地了啊
        ans.extend(path) # 妙啊，厉害。不是append()
        return
    for dirx, diry in directs:
        new_i = i+dirx
        new_j = j+diry
        if 0<=new_i<n and 0<=new_j<m and matrix[new_i][new_j] == 0:
            path.append([i,j]) # 可以走
            matrix[i][j] = 2 #走过的路不要走，标记成2
            dfs(new_i, new_j, path, ans)
            path.pop()
def result():
    ans = []
    dfs(0,0,[],ans)
    ans.append([n-1,m-1]) # 由于踏入了终点就返回，因此这里要补终点进来,这个牛逼啊。
    for i, j in ans:
        print(f"{i},{j}")
result()