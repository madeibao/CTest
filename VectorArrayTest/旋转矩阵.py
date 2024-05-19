

class Solution:
    def rotate(self, matrix) -> None:
        n = len(matrix)
        # 水平翻转
        i = 0
        j = n -1
        while i < j:
            # 每一列上下翻转
            for k in range(n):
                matrix[i][k], matrix[j][k] = matrix[j][k], matrix[i][k]
            i += 1
            j -= 1

        # 对角线翻转
        for x in range(n):
            for y in range(x):
                matrix[x][y], matrix[y][x] = matrix[y][x], matrix[x][y]

    def rotate2(self, matrix) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        # 方法二
        l = len(matrix)
        # 先以对角线（左上-右下）为轴进行翻转
        for i in range(l - 1):
            for j in range(i+1,l):
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp

        # 每一行中点两边交换元素交换
        mid = l >> 1
        for i in range(l):
            for j in range(mid):
                temp = matrix[i][j]
                matrix[i][j] = matrix[i][l-1-j]
                matrix[i][l-1-j] = temp

    # 方法三： 多使用一个矩阵,内存较大
    def rotate2(self, matrix) -> None:

        n = len(matrix)
        matrix_ = [i.copy() for i in matrix]
        for i in range(n):
            for j in range(n):
                matrix_[j][n-1-i] = matrix[i][j]
        # 注意这里是引用拷贝 不能写成 matrix = matrix_
        matrix[:] = matrix_


    # 翻转m次
    def num(self, matrix, m):
        while m > 0:
            self.rotate(matrix)
            m -= 1
        print([x for x in matrix])

if __name__ == '__main__':
    s = Solution()
    m = [[1,2,3],[4,5,6],[7,8,9]]
    s.num(m, 3)