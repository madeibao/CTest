




#include <iostream>
using namespace std;

void heapfi(int tree[], int n, int i)  //对一颗完全二叉树的指定非叶子节点及其叶子结点进行堆的建立
{
	if (i >= n) {  //如果i>=n的时候，证明数组中的元素都已经建立成大根堆了，这是递归终止标志
		return;
	}
	int lchild = i * 2 + 1;    //左孩子节点的下标
	int rchild = i * 2 + 2;   //右孩子节点的下标
	int max = i;              //默认数值最大的节点为该非叶子节点的值
	if (lchild < n && tree[lchild] > tree[max]) {  //判断左孩子节点是否在索引范围内及左孩子结点值是否大于根节点
		max = lchild;           //大于的话就将较大值的下标记录在max中
	}
	if (rchild < n && tree[rchild] > tree[max]) {   //同上
		max = rchild;
	}
    
	if (max != i) {
		swap(tree[max], tree[i]);   //如果最大值的下标改变，则需要交换两个下标所对应的值
		heapfi(tree, n, max);   //对剩下的不是完全二叉树的元素继续进行堆的建立
	}
}

void build_heap(int tree[], int n)
{
	int last_node = n - 1;
	int parent = (last_node - 1) / 2;  //从一棵树的最后一个非叶子节点开始建立堆
	for (int i = parent; i >= 0; i--)
	{
		heapfi(tree, n, i);
	}
}

void heap_sort(int tree[], int n) {   //堆排序
	build_heap(tree, n);  //先建立一个大根堆
	for (int i = n - 1; i >= 0; i--)  //循环交换大根堆中的第一个元素和最后一个元素，并将交换后的最后一个元素出局
	{
		swap(tree[i], tree[0]);  //交换第一个元素和最后一个元素
		heapfi(tree, i, 0);    //调整剩下元素的位置，构建一个新的大根堆，从i号元素开始，即是将交换后的最后一个元素出局
	}
	// return tree;
}

int main() {

	int arr[] = { 2, 5, 3, 1, 10, 4 };
	int n = 6;
	cout << "排序前：" << endl;
	for (int i = 0; i < n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	heap_sort(arr, n);

	cout << "排序后："<< endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
