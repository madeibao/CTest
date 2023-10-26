


'''
3 2 5
3
100
200
400

'''


m,n,k=map(int, input().split())
x = int(input())
prices = [int(input()) for i in range(x)]
print(m,n,k)
print(prices)



def fullsubtraction(price, m):
    while price >=100 and m>0:
        price -= int(price/100) *10
        m-=1
    return price, m

def discount(price,n):
    if n >= 1:
        price = int(price * 0.92)
    return price, n-1

def threshold(price, k):
    while price > 0 and k>0:
        price-=5
        price = max(price, 0) # # 无门槛券过多会导致优惠后总价小于 0，此时我们应该避免
        k-=1
    return price, k

for price in prices:
    ans = []
    resM = fullsubtraction(price, m) # 先满减
    resMN_N = discount(resM[0], n) # 满减后再打折。
    ans.append((resMN_N[0], m+n-(resM[1]+resMN_N[1])))
    resMK_K = threshold(resM[0], k) # 满减后，在无门槛
    ans.append((resMK_K[0], m+k-(resM[1]+resMK_K[1])))

    resN = discount(price, n) # 先打折
    resNM_M = fullsubtraction(resN[0], m) # 先打折后满减。
    ans.append((resNM_M[0], n+m-(resN[1]+resNM_M[1])))

    resNK_K = threshold(resN[0], k) # 先打折，后无门槛
    ans.append((resNK_K[0], n+k-(resN[1]+resNK_K[1])))
    # 对 ans 进行排序，排序规则是：优先按剩余总价升序，如果剩余总价相同，则再按“使用掉的券数量”升序
    ans.sort(key=lambda x:(x[0], x[1]))
    print(" ".join(map(str, ans[0])))