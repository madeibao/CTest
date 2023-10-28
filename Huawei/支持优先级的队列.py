# 输入获取
line = input()
# 这个输入处理绝了。学习下。
tasks = list(map(lambda s: list(map(int, s.split(","))), line[1:len(line)-1].split("),(")))
# tasks = [[10, 1], [20, 1], [30, 2], [40, 3]]
# tasks = [[10, 1], [10, 1], [30, 2], [40, 3]]
 
# (10,1),(20,1),(30,2),(40,3)
# 核心代码
def getResult():
    dic = {}
 
    for num, priority in tasks:
        # 创建默认的字典。
        dic.setdefault(priority, {})
        dic[priority].setdefault(num, None)
 
    order = list(dic.keys()) # 把字典的key拿出来。key就是优先级呀。
    order.sort(reverse=True) # 优先级高的先出来呀。所以要倒序排列呀
 
    ans = []
    for p in order:
        ans.extend(list(dic[p].keys()))
 
    return ",".join(map(str, ans))
 
 
# 算法调用
print(getResult())