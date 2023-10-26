

https://blog.csdn.net/SD_JZZ/article/details/132305156

import numpy

class Solution:
    def sequenceDescribe(self, n, q, arr1, arr2, arr3):
        res = []
        for i in range(q):
            x, y = arr3[i]
            flag = False
            j = 0
            while not flag and j <= n:
                if j >= n:
                    res.append(0)
                    flag = True
                elif j < n and (int(arr1[j]) < int(x) or int(arr2[j]) < int(y)):  # 不满足同时大于x,y，计数器+1
                    j += 1
                else:
                    res.append(n - j)
                    flag = True
        return res
 
 
if __name__ == '__main__':
    s = input("input n,q:").split(' ')
    n = int(s[0])
    q = int(s[1])
    arr1 = numpy.array(input("arr1:").split(' '))
    arr2 = numpy.array(input("arr2:").split(' '))
    arr3 = list()
    for i in range(q):
        arr = numpy.array(input("input x,y:").split(' '))
        arr3.append(arr)
 
    solution = Solution()
    print(solution.sequenceDescribe(n, q, arr1, arr2, arr3))