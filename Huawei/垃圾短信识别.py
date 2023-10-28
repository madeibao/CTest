# n = int(input())
# arr = [list(map(int, input().split())) for i in range(n)]
# tid = input()
# print(n)
# print(arr)
# print(tid)


n = 15
arr = [[1, 2], [1, 3], [1, 4], [1, 5], [1, 6], [1, 7], [1, 8], [1, 9], [1, 10], [1, 11], [1, 12], [1, 13], [1, 14], [14, 1], [1, 15]]
tid = 1

def result(arr, tid):
    # send 记录 tid 发送短信给“哪些人
    send = []
    # receive 记录 “哪些人”发送短信给 tid
    receive = []
    # sendCount 记录 tid 发送了“几次”（对象属性值）短信给某个人（对象属性）
    sendCount = {}
    # receiveCount 记录 某人（对象属性）发送了“几次”（对象属性值）短信给 tid
    receiveCount = {}
    for sid, rid in arr:
        # sid rid 都有可能为tid
        if sid == tid:
            send.append(rid) # 发送的要加。
            if sendCount.get(rid) is None:
                sendCount[rid] = 1 # 发送的记录
            else:
                sendCount[rid]+= 1
        # 如果是要找的tid
        if rid == tid:
            # 要判断tid是否为垃圾短信的发送者。
            receive.append(sid) # 发送者。
            if receiveCount.get(sid) is None:
                receiveCount[sid] = 1
            else:
                receiveCount[sid] += 1
    sendSet = set(send) # send 记录 tid 发送短信给“哪些人，去重，
    receiveSet = set(receive)## receive 记录 “哪些人”发送短信给 tid 去重。
    # connect 记录和 tid 有交互的 id 找到A发送短信的接收者中，发过短信给A的人数
    connect = list(filter(lambda x:x in receiveSet, list(sendSet)))
    # A发送短信的接收者中，没有发过短信给A的人数L>5;
    I = len(sendSet)-len(connect)
    m=len(send)-len(receive)
    isSpammers = I>5 or m>10
    # 如果已经通过 l 和 m 确定了 tid 是垃圾短信发送者，那就不需要再确认 n 了，否则还是需要确认 n
    # 如果存在X，A发送给X的短信数-A接收到X的短信数N>5;
    if not isSpammers:
        for i in connect:
            if (sendCount.get(id) or 0) - (receiveCount.get(id) or 0) > 5:
                isSpammers = True
                # 一旦发现 x,则可以判断，则确定 tid 是垃圾短信发送者, 可提前结束循环
                break
    return f"{isSpammers} {I} {m}"
print(result(arr, tid))