

#include <iostream>
#include <cassert>
 
using namespace std;
int sum(int A[], int from, int to) { 
    int total = 0; 
    for (int i = from; i <= to; i++) 
        total += A[i]; 
    return total; 
} 
//递归的暴力搜素算法
//指数时间的复杂度
int partition(int A[], int n, int k) { 
    if (k == 1) 
        return sum(A, 0, n-1); 
    if (n == 1) 
        return A[0]; 
 
    int best = INT_MAX; 
    for (int j = 1; j <= n; j++) 
        best = min(best, max(partition(A, j, k-1), sum(A, j, n-1))); 
 
    return best; 
}
 
//改进的动态规划算法
//时间复杂度：O(kN2)
//空间复杂度：O(kN) 
const int MAX_N = 100; 
int findMax(int A[], int n, int k) { 
    int M[MAX_N+1][MAX_N+1] = {0}; 
    int cum[MAX_N+1] = {0}; 
    for (int i = 1; i <= n; i++) 
        cum[i] = cum[i-1] + A[i-1]; 
 
    for (int i = 1; i <= n; i++) 
        M[i][1] = cum[i]; 
    for (int i = 1; i <= k; i++) 
        M[1][i] = A[0]; 
 
    for (int i = 2; i <= k; i++) { 
        for (int j = 2; j <= n; j++) { 
            int best = INT_MAX; 
            for (int p = 1; p <= j; p++) { 
                best = min(best, max(M[p][i-1], cum[j]-cum[p])); 
            } 
            M[j][i] = best; 
        } 
    } 
    return M[n][k]; 
}
 
 
int getMax(int A[], int n) { 
    int max = INT_MIN; 
    for (int i = 0; i < n; i++) { 
        if (A[i] > max) max = A[i]; 
    } 
    return max; 
} 
 
int getSum(int A[], int n) { 
    int total = 0; 
    for (int i = 0; i < n; i++) 
        total += A[i]; 
    return total; 
} 
 
int getRequiredPainters(int A[], int n, int maxLengthPerPainter) { 
    int total = 0, numPainters = 1; 
    for (int i = 0; i < n; i++) { 
        total += A[i]; 
        if (total > maxLengthPerPainter) { 
            total = A[i]; 
            numPainters++; 
        } 
    } 
    return numPainters; 
} 
 
 
//想不到的二分查找算法
//时间复杂度：O(N log ( ∑ Ai )).
//空间复杂度：0(1)
int BinarySearch(int A[], int n, int k) { 
    int lo = getMax(A, n); 
    int hi = getSum(A, n); 
 
    while (lo < hi) { 
        int mid = lo + (hi-lo)/2; 
        int requiredPainters = getRequiredPainters(A, n, mid); 
        if (requiredPainters <= k) 
            hi = mid; 
        else
            lo = mid+1; 
    } 
    return lo; 
}
int main()
{
    enum{length=9};
    int k=3;
    int a[length]={9,4,5,12,3,5,8,11,0};
    cout<<partition(a,length,k)<<endl;
    cout<<findMax(a,length,k)<<endl;
    cout<<BinarySearch(a,length,k)<<endl;
    return 0;
}