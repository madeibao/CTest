


queue = input().split(",")
# hello,2,ok,0,bye,0,test,0,one,1,two,1,a,0
print(queue)


def recursive(queue, level, childCount,tree):
    # 遍历处理
    for i in range(childCount):
        comment = queue.pop(0)
        if len(tree)<level:
            tree.append([])
        # 因为传进来的是level 他的下标应该比他小1。数组的index 与len的len = index+1
        tree[level-1].append(comment)
        # 拿到子评论的长度
        count = int(queue.pop(0))
        # 终止条件在这里。大于0就递归下去，等于0就返回。
        if count > 0:
            recursive(queue, level+1, count,tree)

def result():
    # 树结构
    tree = []
    # 根评论层级为1
    level = 1
    while len(queue)>0:
        # 根评论
        comment = queue.pop(0)
        # 如果树还有对应的层级，就要初始化对应的层级
        if len(tree) < level:
            tree.append([])
        # 将根评论加入树结构的第一层
        tree[0].append(comment)
        # 然后拿到该根评论有几个直接的子评论，相当于拿到子孩子。
        childCount = int(queue.pop(0))
        # 按照上面的逻辑，递归处理子评论，子评论所在的级别为level+1
        recursive(queue, level+1, childCount,tree)
    # 树结构的高度，就是评论嵌套的最大深度
    print(len(tree))
    # 打印每一层的点。
    for nodes in tree:
        print(" ".join(nodes))
result()




