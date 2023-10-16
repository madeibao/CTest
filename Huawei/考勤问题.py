
2
present
present absent present present leaveearly present absent

-------------------------------------------------------------------------------------------------------------------------------

n = int(input())
kq_list = []
for i in range(n):
    kq_list.append(input().split())

# kq_list = [['present'],['present','present','leaveearly','absent','leaveearly','present','present']]

l = []
for kq in kq_list:
    # 1.缺勤不能超过1次
    if kq.count('absent') >1:
        l.append('false')
        continue

    #2.没有连续的迟到/早退
    for i in range(len(kq)-1) :
        a= kq[i]
        b =kq[i+1]
        if a in ['late','leaveearly'] and b in ['late','leaveearly']:
            l.append('false')
            break
    else:
        #3.任意连续7次考勤 缺勤/迟到/早退 不超过3次
        for i in range(len(kq)-6):
            temp_list = kq[i:i+7]
            d,e,f =0,0,0
            for j in temp_list:
                if j == 'absent':
                    d +=1
                elif j=='late':
                    e +=1
                elif j == 'leaveearly':
                    f +=1
            if d+e+f > 3:
                l.append('false')
                break
        else:
            l.append('true')
print(l)