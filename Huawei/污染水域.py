
# import math

# arr = list(map(int, input().split(",")))
# print(arr)

# def result(arr):
#     n = int(math.sqrt(len(arr)))
#     matrix = [[0]*n for i in range(n)]
#     total = len(arr)
#     # 统计污染源
#     queue = []
#     for i in range(n):
#         for j in range(n):
#             matrix[i][j] = arr[i*n+j]
#             if matrix[i][j] == 1:
#                 queue.append([i, j])
#                 total -= 1 # 统计多少未污染的嘛
#     if len(queue) == 0 or len(queue) == len(arr):
#         return -1
#     directs = ((-1,0), (1,0), (0,-1),(0,1))
#     while len(queue)>0 and total>0:
#         newque = []
#         for i, j in queue:
#             num = matrix[i][j]
#             for dirx, diry in directs:
#                 new_x = i + dirx
#                 new_y = j + diry
#                 if 0<=new_x<n and 0<= new_y <n and matrix[i][j] == 0:
#                     matrix[new_x][new_y] = num+1
#                     newque.append([new_x, new_y])
#                     total -= 1
#                     if total == 0: # 优秀啊。不用减去1了。
#                         return num
#         queue = newque
# # 算法调用

# result(arr)




# # 1,0,1,0,0,0,1,0,1


import math

link = list(map(int, input().split(",")))
n = int(math.sqrt(len(link)))
mat = [[0]*n for _ in range(n)]



def func():
    q = []
    for i in range(n):
        for j in range(n):
            mat[i][j] = link[i*n+j]
            if link[i*n+j]==1:  # 如果是污染区
                q.append([i,j])


    if not q or len(q) == len(link):
        return -1




    while q: # 只要q中有东西就一直遍历
        directions = [[1,0],[-1,0],[0,1],[0,-1]] # 四个方向
        max_num = 0    # 求最大天数，所以初始化为一个比较小的数

        cur  = q.pop(0) # 取出队列的第一个值
        x, y = cur # 当前位置
        for di in directions:  # 遍历四个方向
            newx = x+di[0]
            newy = y+di[1]
            if newx<0 or newy<0 or newx>=n or newy>=n:
                continue # 如果越界就跳过
            if mat[newx][newy]!=0:
                continue # 如果访问过就跳过
            mat[newx][newy] = mat[x][y]+1 # 标记当前位置，用的数字可以代表与污染区的距离【也就是扩散用的时间】
            if max_num < mat[newx][newy]:
                max_num = mat[newx][newy] # 更新最大天数
            q.append([newx,newy])
    return max_num-1 # 因为mat[x][y]的初始值是1，所以这里要-1


if __name__=="__main__":
    print(func())