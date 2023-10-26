m =5
relations = [[8, 6], [10, 8], [6, 0], [20, 8], [2, 6]]
remove = 8
 
def dfs(tree, node, remove, res):
    # 如果节点值不为空
    if tree.get(node) is not None:
        children = tree[node] # 拿到他的子节点，
        for child in children: # 遍历子节点
            if child != remove: 
                # 如果子节点不等于要删除的节点，如果要删除节点就直接跳过，相当于整棵子树都跳过
                res.append(child) # 添加到结果里。
                dfs(tree, child, remove, res)
# 算法入口
def getResult():
    tree = {}
    for child, father in relations:
        if tree.get(father) is None:
            tree[father] = []
        tree[father].append(child)
    print(tree)
    if remove == 0:
        return ""
    res = []
    dfs(tree, 0, remove, res)
    res.sort()
    return " ".join(map(str, res))
# 调用算法
print(getResult())


# m = int(input())
# arr = [list(map(int, input().split())) for i in range(m)]
# tar = int(input())
# print(m)
# print(arr)
# print(tar)

# result(m,arr,tar)