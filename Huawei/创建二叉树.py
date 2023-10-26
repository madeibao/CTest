

# 创建节点类
class Node:
    def __init__(self,val) -> None:
        self.val = val
        self.left = None
        self.right = None
def result():
    # 先初始化，值为-1
    tree = [[Node(-1)]]
    # len(tree)就是层数+1
    for i in range(len(operations)):
        height, index = operations[i]
        # 判断新增一层。比如，第0层的对应长度为1，第1层对应长度为2.len(tree)
        # 不新加层的话，len(tree) >= height+1
        if len(tree) <= height + 1:
            tree.append([]) # 因为下面要加左右孩子了。
        ch = Node(i) # 先创建值为i的节点。然后我们去找其父节点。
        fa = tree[height][index]
        # 如果左右孩子有一个为空
        if not fa.left or not fa.right:
            tree[height+1].append(ch) # 这一步厉害啊。
        # 如果左孩子为空
        if not fa.left:
            fa.left = ch
        elif not fa.right:
            fa.right = ch
    # 搞完了,需要进行层序遍历。广度优先，用队列实现。
    ans = []
    que = [tree[0][0]] # 初始化队列
    while len(que)>0:
        # 拿出节点
        node = que.pop(0)
        if node is not None:
            # 如果该节点不为空
            ans.append(node.val)
            # 把左右孩子都添加进去。不用判断是否为空的。为空判断交给下一次遍历的时候判断。
            que.append(node.left)
            que.append(node.right)
        else:
            # 节点为空了添加null
            ans.append("null")
    # 到此为止que搞定了。我们现在要去掉哪些没必要的null
    while True:
        # 去掉最后的null，中间的null不用去掉。
        if ans[-1] == "null":
            ans.pop()
        # 只要最后一个不是null，就结束循环。
        else:
            break
    return ans

if __name__=="__main__":
    # 输入获取
    operations = eval(input())
    # [[0,0],[1,0],[1,0],[2,1],[2,1],[2,1],[2,0],[3,1],[2,0]]
    print(operations)
    print(result())
