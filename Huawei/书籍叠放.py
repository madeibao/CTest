

# 输入获取
books = eval(input())
 

 
def result():
    books.sort(key= lambda x:(x[0], -x[1]))
    N = len(books)
    res = 0
    dp=[1]*N
    for i in range(N):
        for j in range(i):
            # 第一维度已经是升序排列了。然后第二维度。如果是升序排列就好了
            if books[j][1]<books[i][1]:
                dp[i] = max(dp[i], dp[j]+1)
    return max(dp)
print(result())