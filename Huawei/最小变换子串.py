




def result():
    minArr = list(s)
    minArr.sort() # 先排序一把
    # 边界判断
    if s == "".join(minArr):# 这里因为minArr已经是list了。
        return s
    sArr = list(s) # 把s搞成list
    # 然后一个个来对比。
    for i in range(len(s)):
        # 因为已经拍好序了，所以第一个出现不同的就要把他揪出来。
        if sArr[i] != minArr[i]:
            # 把sArr[i] 存好，
            tmp = sArr[i]
            # 把sArr[i]替换成minArr[i]
            sArr[i] = minArr[i]
            # 接下来就要找tmp 在sArr的位置了。从右边开始找。
            swapIdx = s.rindex(minArr[i])
            sArr[swapIdx] = tmp
            # 找到了就break结束循环
            break
    return "".join(sArr)




if __name__=="__main__":
    s = input()
    print(result())