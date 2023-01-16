// 沙滩按照线型摆放着n个大小不一的球形石头，已知第i个石头的半径为ri，且不存在两个石头有相同的半径。
// 为了使石头的摆放更加美观，现要求摆放的石头的半径从左往右依次递增。因此，需要对一些石头进行移动，
// 每次操作可以选择一个石头，并把它放在剩下n−1个石头在最左边或最右边。问最少需要操作多少次才能将这n个石头的半径变成升序？

// 第一行一个整数n，表示石头的个数。(1 <= n <= 100000) 第二行n个整数，表示从左往右石头的半径r1，r2，…，rn。(1 <= ri <= n)，且保证不存在两个不同的石头拥有相同的半径。

// 输出
// 最少操作次数

// 这道题要是想到就是求序列中最长的递增序列（但是这个递增序列是每个相差1）就好办了。
// ————————————————
// 版权声明：本文为CSDN博主「盒子6910」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/weixin_42738495/article/details/105765601


#include<iostream>
#include<vector>
using namespace std;
int main() {

	int n;
	cin >> n;
	vector<int>nums(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int max_count = 1;
	for (int i = 0; i < n; i++) {
		int k = nums[i];
		int tmp = 1;
		for (int j = i + 1; j < n; j++) {
			if (k + 1 == nums[j]) {
				tmp++;
				k = nums[j];
			}
		}
		if (tmp > max_count) {
			max_count = tmp;
		}
	}
	cout << n - max_count << endl;
	system("pasue");
	return 0;
}
