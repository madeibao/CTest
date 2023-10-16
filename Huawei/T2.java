
public class T2 {
	public static void main(String[] args) {
		String input2="128#168#100#5";
		String input = "100#101#1#5";
		String[] ipArr=input.split("#");
		//长度校验
		if(ipArr.length!=4){
			System.out.println("invalid IP");
			System.exit(0);
		}

		// 数字范围校验
		if(1>Integer.parseInt(ipArr[0])||Integer.parseInt(ipArr[0])>128){
			System.out.println("invalid IP");
			System.exit(0);
		}

		// 后面的几个位置
		for(int i=1;i<4;i++){
			if(0>Integer.parseInt(ipArr[i])||Integer.parseInt(ipArr[i])>255){
				System.out.println("invalid IP");
				System.exit(0);
			}
		}
		for(var j:ipArr) {
			System.out.print(j+" ");
		}

		System.out.println();
		//10进制转换为16进制
		String oxStr="";
		for(int i=0;i<4;i++){
			ipArr[i]=Integer.toString(Integer.parseInt(ipArr[i]),16);

			if(ipArr[i].length()==1){
				ipArr[i]="0"+ipArr[i];
			}
			oxStr+=ipArr[i];
		}
		System.out.println(oxStr);
		//16进制转换为10进制

		
		
		System.out.println(Long.parseLong(oxStr, 16));
	}
}
