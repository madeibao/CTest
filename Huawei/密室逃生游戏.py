

# 密室逃生游戏
key = input()
# 注意：用例的第二行输入有问题，这里假设第二行输入为：["s", "sdf134 A2c4b"]
boxes = eval(input())
print(key)
print(boxes)


def result(key, boxes):
    sorted(key)
    for i in range(len(boxes)):
        box = boxes[i]
        if len(box) < len(key):
            # 不符合要求，只能continue
            continue
        box = sorted(box.lower()) # 按照小写字母排序
        j = 0
        k = 0
        while k < len(key) and j<len(box):
            if box[j] == key[k]:
                k += 1
            j += 1
            if k == len(key):
                return i+1
    return -1


print(result(key,boxes))

