
def bs(arr, tar):
    l = 0
    r = len(arr)
    while l < r:
        m = (l+r)//2
        if arr[m] == tar:
            return m
        elif arr[m] < tar:
            l = m + 1
        else:
            r = m
    # 都没返回
    return -l -1

def result():
    cakes.sort() # 升序序列，这个数列有可能是不严格递增的
    print("cakes:",cakes)
    ans = 0
    for gift in gifts:
        if tar <=gift:
            continue
        maxCake = tar - gift
        print("maxCake:", maxCake)
        i = bs(cakes, maxCake)
        if i>=0:
            print(f"i大于0, i={i}")
            ans += i+1
        else:
            # i<0了
            print("gift:", gift)
            print(f"i小于0, i:{i}, -i-1: {-i-1}")
            i = -i-1
            ans += i
    return ans


if __name__=="__main__":

    cakes = list(map(int, input().split(",")))
    gifts = list(map(int, input().split(",")))
    tar = int(input())
    print(cakes)
    print(gifts)
    print(tar)
    print(result())



输入：
10,20,5
5,5,2
15