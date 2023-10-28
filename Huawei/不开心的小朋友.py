n = int(input())
kids = input().split()
print(n)
print(kids)


def result():
    # 不开心的小朋友数量
    unHappy = 0
    playing = set()
    waiting = []
    for kid in kids:
        if kid in playing:
            # 如果kid是摇摇车上的小朋友编号, 代表他已经排队进去了，并且再玩了，
            # 再次出现，则代表kid玩好了要离开。
            playing.remove(kid)
            # 如果kid离开后，摇摇车有空位了，如果此时有人排队，则让排队的人上车玩
            if len(waiting)>0:
                # 这里要判断waiting是否为空啊，因为后面他要弹出来 跑到playing里去。
                playing.add(waiting.pop(0))
            continue
        # 如果kid不是摇摇车上的小朋友，则检查kid是不是排队的小朋友
        if kid in waiting:
            # 不在playing里，而是在waiting里，说明人家已经等待了，再次出现，就说明要走了
            unHappy+=1
            waiting.pop(waiting.index(kid))
            continue
        # 如果kid既不是摇摇车上的小朋友，也不是排队的小朋友，则是新来的小朋友
        if len(playing)<n:
            # 如果摇摇车还有空位，则直接玩
            playing.add(kid)
        else:
            # 如果摇摇车没有空位了，则需要排队
            waiting.append(kid)
    return unHappy
print(result())