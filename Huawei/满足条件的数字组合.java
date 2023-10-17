


import java.util.Scanner;

public class Y1 {
	static int rawNums[]=null;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int num=Integer.parseInt(sc.nextLine());
		rawNums=new int[num];
		for(int i=0;i<num;i++) {
			rawNums[i]=sc.nextInt();
		}
		for(int i=0;i<num;i++) {
			for(int j=0;j<num;j++) {
				for(int k=0;k<num;k++) {
					if(i==j||i==k||k==j)continue;
					if(rawNums[i]==rawNums[j]+2*rawNums[k]) {
						System.out.println(rawNums[i]+" "+rawNums[j]+" "+rawNums[k]);
						System.exit(0);
					}
					if(rawNums[i]==rawNums[k]+2*rawNums[j]) {
						System.out.println(rawNums[i]+" "+rawNums[k]+" "+rawNums[j]);
						System.exit(0);
					}
				}
			}
		}
		System.out.println(0);
	}
}
