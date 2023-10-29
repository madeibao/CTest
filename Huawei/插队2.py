

import queue
 
# 输入获取
n = int(input())
seq = [input().split() for _ in range(n)]
 
 
# 定义一个客户类，实现自定义优先级
class Customer:
    def __init__(self, num, x, index):
        """
        :param num: 客户编号
        :param x: 客户优先级
        :param index: 客户先来后到顺序
        """
        self.num = num
        self.x = x
        self.index = index
 
    def __lt__(self, other):
        if self.x != other.x:
            return self.x < other.x
        else:
            return self.index < other.index
 
 
# 算法入口
def getResult(n, seq):
    pq = queue.PriorityQueue()
 
    for i in range(n):
        tmp = seq[i]
 
        if tmp[0] == 'a':
            num = int(tmp[1])
            x = int(tmp[2])
            pq.put(Customer(num, x, i))
        elif tmp[0] == 'p':
            if pq.qsize() > 0:
                customer = pq.get()
                print(customer.num)
            else:
                print("")
 
 
# 算法调用
# getResult(n, seq)

print(getResult(n,seq))

