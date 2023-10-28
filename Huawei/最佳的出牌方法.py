

cards = input()
# 33445677
print(cards)


def getScore(cardCnt, i):
    score = 0
    count = cardCnt[i]
    if count == 1:
        score += i
    elif count == 2 or count == 3:
        # 对子三张，得分都是i*牌数量*2
        score += i * count * 2
    elif count == 4:
        # 炸弹 i*牌数量*4
        score += i * count * 3
    return score

def shunZi(cardCnt, l):
    profit = 0
    for i in range(l, l+5):
        # 如果在l,r区间无法组成顺子，就没有好处
        count = cardCnt[i]
        if count == 0:
            return -10000000
        if count == 1:
            # 单行 成为顺子的一部分，增值的分数应该是i
            profit += i
        elif count == 2:
            # 对子，拆开一张给顺子，一张成为了单张，损失了i
            profit -= i
        # 三张没有损失，所以代码不写
        elif count == 4:
            # 炸弹拆一张给顺子，剩余的变成了三张，损失了4i
            profit -= i*4
    return profit

def maxScore(cardCnt):
    # 记录最大得分
    score = 0
    # 五张连续牌要是组成顺子的增值分数 > 0, 则可以尝试组成顺子, 否则各论各的得分更高
    while True:
        maxProfit = 0
        l = 0
        # 顺子的起始位置, cardCnt[0]是无用的，因此l=0表示没有顺子
        # 顺子起始位置只能是0-9，12345最先顺子，90JQK是最大的顺子了
        for i in range(1, 10):
            profit = shunZi(cardCnt, i)
            # 更新maxProfit
            if profit > maxProfit:
                maxProfit = profit
                l = i
        if l == 0:
            # 就是没有找到顺子
            break
        # 找到顺子就要加入顺子的分数，并且从cardCnt中去掉对应得统计值
        for i in range(l, l+5):
            score += i*2
            cardCnt[i] -= 1
    # 找完所有的顺子，剩余牌各论各的得分
    for i in range(1, 14):
        score += getScore(cardCnt, i)
    return score

def result():
    # 数组索引是牌面分数, 数组元素是牌面数量, 其中 0 索引不用
    cardCnt = [0]*14
    # 统计各种牌的数量
    for c in cards:
        # 1-9输入为数字1-9，10输入为数字0，JQK输入为大写字母JQK
        # 1-9 牌面分数就是 1-9, 0的牌面分数是 10, J=11,Q=12,K=13, 可以发现牌面分数是连续的，可以和数组的索引对应起来    
        if c == "0":
            cardCnt[10] += 1
        elif c == "J":
            cardCnt[11] += 1
        elif c == "Q":
            cardCnt[12] += 1
        elif c == "K":
            cardCnt[13] += 1
        else:
            i = ord(c)-ord("0")
            cardCnt[i] += 1
    return maxScore(cardCnt)
print(result())