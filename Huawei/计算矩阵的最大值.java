public class 计算矩阵的最大值 {
	public static void main(String[] args) {
		int number = 5;
		int[][] numArr = { { 1, 0, 0, 0, 1 }, { 0, 0, 0, 1, 1 },
						   { 0, 1, 0, 1, 0 }, { 1, 0, 0, 1, 1 }, 
						   { 1, 0, 1, 0, 1 } 
						 };
		// number = 3;
		// int[][] numArr ={{1,0,1},{0,1,0},{0,0,1}};
		int sum = 0;// 最后的和
		for (int[] arr : numArr) {
			int[] tmpArr = arr;
			int max = 0;
			for (int i = 0; i < arr.length; i++) {
				tmpArr = toRight(tmpArr, number);
				String binStr = "";
				for (int j = 0; j < tmpArr.length; j++) {
					// System.out.print(tmpArr[j] + ",");
					binStr += tmpArr[j];
				}
				int num = Integer.parseUnsignedInt(binStr, 2);
				if (max < num) {
					max = num;
				}
				System.out.println("单行最值：" + max);
			}
			sum += max;// 每行的最大值相加
			System.out.println("_________");
		}
		System.out.println("矩阵的最大值为：" + sum);
	}



	public static int[] toRight(int[] arr, int n) {
		// 右移一位
		int tempArr[] = arr.clone();
		for (int i = 1; i < arr.length - 1; i++) {
			tempArr[i] = arr[i - 1];
		}
		tempArr[0] = arr[arr.length - 1];
		tempArr[arr.length - 1] = arr[arr.length - 2];
		return tempArr;
	}
}
