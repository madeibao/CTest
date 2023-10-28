

def result():
    #统计arr1里的整数出现的次数
    cnt1 = {}
    for i in arr1:
        cnt1[i] = cnt1.get(i, 0) + 1
    #统计arr2里的整数出现的次数
    cnt2 = {}
    for i in arr2:
        cnt2[i] = cnt2.get(i, 0) + 1
    # print(cnt1)
    # print(cnt2)
    # arr1 和arr2是否存在相同的数字，假设不存在，
    noSameNum = True
    # 存在的话，key为共同存在的数字次数，value是相同的数字。
    sameNum = {}
    for k1 in cnt1.keys():
        # 如果k1在cnt2中，说明存在相同的数字。
        if k1 in cnt2.keys():
            noSameNum = False
            # 先按照同时出现次数(整数在两个数组中都出现并且出现次数较少的那个)进行归类
            count = min(cnt1[k1], cnt2[k1])
            # 写入sameNum中
            if sameNum.get(count) is None:
                sameNum[count] = []
            sameNum[count].append(k1)
    # 分情况讨论，没有同时出现的整数时，输出NULL。
    if noSameNum:
        print("NULL")
        return
    # 存在相同的然，按照出现次数从小到大依次按行输出。
    tmp = list(sameNum.keys())
    tmp.sort()
    # 输出格式为 出现次数：该出现次数下的整数升序排序的结果
    for i in tmp:
        sameNum[i].sort()
        print(f"{i}:{','.join(map(str, sameNum[i]))}")
result()


