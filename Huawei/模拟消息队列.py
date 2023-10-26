


def result():
    pub = []
    for i in range(0, len(pubArr), 2):
        # 将第一行输入两个一组，收集到：发布者数组中
        pub.append([pubArr[i], pubArr[i+1]])
    sub = []
    for i in range(0, len(subArr), 2):
        sub.append([subArr[i], subArr[i+1]])
    # 按照发布时刻升序：发布者数组
    pub.sort(key= lambda x:x[0])
    # 为每个订阅这构造一个订阅内容集合
    subcon = [[] for i in range(len(sub))]
    # 遍历发布者
    for pubtime, pubcon in pub:
        for j in range(len(sub)-1, -1, -1):
            subtime, unsubtime = sub[j]
            # 如果 订阅时刻 <= 发布时刻 < 取消订阅时刻
            if unsubtime>pubtime>= subtime:
                # 那么该订阅者就可以收到发布的内容
                subcon[j].append(pubcon)
                # 题目说，发布内容只会被最高优先级的订阅者收到
                break
    for content in subcon:
        if len(content) == 0:
            print("-1")
        else:
            print(" ".join(map(str, content)))


if __name__=="__main__":
    pubArr = list(map(int, input().split()))
    subArr = list(map(int, input().split()))
    # 2 22 1 11 4 44 5 55 3 33
    # 1 7 2 3 
    print(pubArr)
    print(subArr)
    print(result())