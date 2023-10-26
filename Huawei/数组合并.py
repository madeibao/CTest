


# coding:utf-8
import numpy
 
 
class Solution:
    def arrMerge(self, n, m, arrs):
        res = ''
        while m > 0:
            for i in range(len(arrs)):
                arr = arrs[i]
                if len(arr) > n-1:
                    res = res + ','.join(arr[:n])+','
                    arr = arr[n:]
                elif (len(arr) <= n-1) and (len(arr) > 0):
                    res = res + ','.join(arr)+','
                    arr = []
                    m -= 1
                elif len(arr) == 0:
                    m -= 1
                arrs[i] = arr
        return res[:-1]
 
 
if __name__ == "__main__":
    n = int(input("请输入目标数组大小："))
    m = int(input("请输入数组数量："))
    arrs = []
    for k in range(m):
        si = input("请输入数组,用,分割：").split(',')
        s = numpy.array(si)
        arrs.append(s)
    solution = Solution()
    print(solution.arrMerge(n, m, arrs))



# 4
# 3
# 1,2,3,4,5,6
# 1,2,3
# 1,2,3,4