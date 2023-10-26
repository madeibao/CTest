


def result():
    kids = list(map(lambda x:x.split("/"), s.split()))
    # print(kids)
    # 边界条件的判断
    if len(kids)>999:
        print("ERROR")
        return 
    one = []
    two = []
    preBelongOne = True # 先假设属于班级1
    for kid in kids:
        idx = int(kid[0])
        # 判断这个idx
        if idx<=0 or idx>999:
            print("ERROR")
            return
        isSameWithPre = "Y" == kid[1] # 与前一个相同。
        # 如果前一个属于1班。
        if preBelongOne:
            # isSameWithPre 为true
            if isSameWithPre:
                one.append(idx)
            # 与前一个为False，那么他属于2班，还要把preBelongOne(前一个属于1班)变为false，这不是属于2班了嘛
            else:
                two.append(idx)
                preBelongOne = False
        # 如果前一个不属于1班，那么前一个属于2班了。也分isSameWithPre也要分两种情况。
        else:
            if isSameWithPre: #与前一个相同，那么属于2班了。
                two.append(idx)
            else: #前一个属于2班，与前一个不同，那么就是属于1班，别忘了isSameWithPre标志要改。
                one.append(idx)
                preBelongOne = True
    # 1.编号需按照升序排列。
    one.sort()
    oneStr = " ".join(map(str, one))
    # 若只有一个班的小朋友，第二行为空行。
    if len(two) == 0:
        print(oneStr)
        print("")
        return 
    # 二班不为空了
    two.sort()
    twoStr = " ".join(map(str, two))
    # 比较两个班级的第一个那个大
    if one[0]<two[0]:
        print(oneStr)
        print(twoStr)
    else:
        print(twoStr)
        print(oneStr)

s = input()
result()