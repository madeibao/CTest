

def result():
    # 先统计str1的字符串的数量。
    count = {}
    for c in str1:
        count[c] = count.get(c, 0) + 1
    total = len(str1) # 获取str1的长度
    # 滑窗三步，1，初始化滑窗，固定还是非固定2.开始滑动，3.终止滑动。
    # 初始化滑窗，要跟str1一样长，这里里边先找找是否有合适的。】
    for i in range(len(str1)):
        # 添加到滑窗里面的
        add = str2[i]
        # 如果新增字符是str1的字符，即count[add] > 0时，则说明滑窗子串已找到一个目标字符，
        # 此时剩余add字符数量count[add]--,剩余目标字符总数total--
        if count.get(add) is not None:
            if count[add]>0:# 这里要判断count[add] > 0，因为他后面有可能出现负数的。如果等于0，后面减去没意义
                total -= 1 # 如果coount[add]<=0了你再减去，对total不能有影响。
            # 不管count[add]是必须要减去1的。
            count[add] -= 1
    # 如果total == 0，则说明滑窗内所有字符都是str1内的字符，由于限定了滑窗的长度就是str1的长度，因此滑窗内字符和str1完全匹配
    if total == 0:
        # 在初始化滑窗就找到了答案。
        return 0
    # 没找到，开始滑窗,滑窗的左端的范围是从1开始，到len(str2)-1-len(str1)+1 = len(str2)-len(str1)。
    # 因为range左闭右开,所以rang(1, len(str2) - len(str1) + 1)
    '''
    本轮滑窗remove字符，在上一轮是被add的字符，我们假设此字符为c：
    # 1、c是str1的字符，则初始统计时count[c]>0，上一轮滑窗加入c字符，则count[c]--，此轮count[c]是有可能>=0或者<0的，
    # 1.1、如果本轮count[c]>=0，则说明上轮滑窗并没有找到所有的c字符，因此本轮移除的c字符可以还原total数量
    # 1.2、如果本轮count[c]<0，这说明上轮滑窗内的c字符超标了，即c字符是目标字符，
    但是滑窗内包含的c字符数量超过了str1中c字符的数量，因此本轮移除c字符是超标部分，不会还原total
    '''
    for i in range(1, len(str2)-len(str1)+1):
        # 踢出滑窗的
        remove = str2[i-1]
        # 进滑窗的，这里一定要画图
        add = str2[i + len(str1)-1]
        # 出去的要还原,如果在count里面，只要key存在，不管value
        if count.get(remove) is not None:
            # 对total起作用的是要count[remove]本身大于等于0
            if count[remove]>=0:#这里要大于等于0，相当于至少要是0，下面马上就要加1，才能对total有影响。如果是-1就没意义
                total += 1
            # 不管count[remove]是否大于0，都要加回去
            count[remove] += 1
        # 处理进滑窗的，跟上面初始化滑窗逻辑一样。
        if count.get(add) is not None:
            if count[add]>0:
                total -= 1
            count[add] -= 1
        # 跟上面滑窗逻辑一样如果total==0，就返回啦。
        if total == 0:
            return i
    # 循环结束后还没有return，只能return -1
    return -1
print(result())