
matrix = 


def result(matrix):
    # 边界判断
    if len(matrix)==0 or len(matrix[0]) == 0:
        return -1
    # 第一行的数据作为每列的初始值。
    col_max = matrix[0]
    for i in range(1, len(matrix)): # 从第二行开始遍历。
        for j in range(len(matrix[i])):
            # 得到每列的最大值。
            col_max[j] = max(col_max[j], matrix[i][j])
    # 所有的列都比完了，我们再比较col_max里边的最小值
    return min(col_max)
result(matrix)