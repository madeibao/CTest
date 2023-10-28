
n = 6
nodes = [[10, 1, 2], [-21, 3, 4], [23, 5], [14], [35], [66]]
tx = 1
ty = 1


def dfs(matrix, node, depth):
    if node is None: # node = [10, 1, 2]
        # 到底部了，返回
        return
    val = node[0] # 第一个是节点的值。
    if depth < len(matrix):
        # 深度小于矩阵的长度 初始化深度为0，长度为1
        matrix[depth].append(val) # 对应的深度，然后添加对应的值。
    else:
        matrix.append([val]) # 深度大于等于矩阵的长度代表开启下一行了。
    for i in range(1, len(node)):# 第0行就是个root啦,往后遍历，才是子节点的行数。
        child = node[i]
        dfs(matrix, nodes[child],depth+1)
    
def result(nodes, tx, ty):
    matrix = []
    # nodes[0]表示第一行。
    dfs(matrix, nodes[0], 0)
    # 边界判断。
    if tx <len(matrix) and ty <len(matrix[tx]):
        # 按照题目要求的格式进行返回
        return "{" + str(matrix[tx][ty]) + "}"
    else:
        return "{}"


print(result(nodes, tx, ty))


