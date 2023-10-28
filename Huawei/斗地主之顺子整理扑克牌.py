

def mapToCard(num):
    if num == 11:
        return "J"
    elif num == 12:
        return "Q"
    elif num == 13:
        return "K"
    elif num == 14:
        return "A"
    else: # 因为顺子从3开始，所以2就不用单独做映射了。int就好了
        return str(num)
def mapToNum(card):
    if card == "J":
        return 11
    elif card == "Q":
        return 12
    elif card == "K":
        return 13
    elif card == "A":
        return 14
    else:
        return int(card)
def isStraights(cout, start, end):
    i = start
    while i <= end:
        if cout[i] == 0:
            break
        else:
            i += 1
    return i>end

def result():
    # 总牌数
    total = len(cards)
    # 记录每张牌的数量
    count = [0] * 15
    for card in cards:
        num = mapToNum(card)
        count[num] += 1
    # 记录顺子
    straights = []
    s = 3 # 从三开始，到10结束，因为顺子要大于等于5
    while s <11:
        if isStraights(count, s, s+4):
            # 如果可以组成五张顺子，则记录该顺子
            straights.append([s, s+4])
            total -= 5 # 去除了5个牌
            for j in range(s, s+5):
                count[j] -= 1 # 牌的计数也要减少。
        else:
            s += 1
    # 如果五张的顺子求解完后，还有剩余牌
    print(straights)
    print(count)
    if total > 0:
        for straight in straights:
            # 遍历，还有那几种牌有剩余。
            for i in range(3, 15):
                # 有剩余的牌，并且比记录的end上大1，就把他加进来。小的已经没意义。为啥，本来就是从小到大排好序的。
                if count[i] > 0 and i-straight[1] == 1:
                    straight[1] = i
                    count[i] -= 1
    # 如果没有顺子就返回No
    if len(straights) == 0:
        print("No")
        return 
    # 有顺子就打印
    for start, end in straights:
        ans = [mapToCard(num) for num in range(start, end+1)]
        print(" ".join(ans))

cards = input().split() # 这里因为有字符，所以不给他转int，都是str类型。
# 2 9 J 10 3 4 K A 7 Q A 5 6
print(cards)
result()