while True:
    try:
        list1 = input().strip().split()
        k = int(input())
        list_index, list2 = [], []
        for i in range(len(list1)):
            list2.append(i)
            if int(list1[i]) < k:
                list_index.append(i)
        len_num = len(list_index)
        max_num = 0
        for index in list_index:
            num = len(set(list_index) & set(list2[index:index + len_num]))
            if num > max_num:
                max_num = num
        min = len_num - max_num
        print(min)
    except:
        break
