
head, n = input().split()
nodes = {}
for i in range(int(n)):
    addr, val, nextAddr = input().split()
    nodes[addr] = [val, nextAddr]
print(nodes)


def result(head, nodes):
    linkedlist = []
    node = nodes.get(head) # 初始化node
    while node is not None:
        # 拿到val ，还有next的指向。
        val, next = node
        linkedlist.append(val)
        node = nodes.get(next) #更新node为下一个节点嘛
    length = len(linkedlist)
    mid = int(length/2)
    return linkedlist[mid]
print(result(head, nodes))


# 10000 3
# 76892 7 12309
# 12309 5 -1
# 10000 1 76892