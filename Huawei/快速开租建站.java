public class SetSiteA {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int taskNum = Integer.parseInt(sc.nextLine());
        int [][] step = new int[taskNum][taskNum];
        int relyNum = Integer.parseInt(sc.nextLine());
        int stepCount = 1;
        List<Integer> comp = new ArrayList<>();
        for (int c = 0; c < taskNum; c++){
            comp.add(c);
        }
 
        for(int i = 0; i < relyNum;i++){
            String [] value = sc.nextLine().toString().split(" ");
            int x = Integer.parseInt(value[0]);
            Integer y = Integer.parseInt(value[1]);
            //构建任务数的矩阵，存在依赖关系的值为1
            step[x][y] = 1;
            comp.remove(y);
        }
        //重复遍历，直到所有任务完成
        while (comp.size() != taskNum){
            //依赖已完成的任务全部刷成0
            Set<Integer> set = new HashSet<>();
            for (int k = 0; k < comp.size();k++){
                for(int j = 0; j < taskNum;j++){
                    //减枝，减少遍历次数
                    if (step[k][j] == 1){
                        set.add(j);
                    }
                    step[k][j] = 0;
                }
            }
            //检查是不是有任务已全部完成,根据Y列，已完成的加入已完成的compList中
            for(Integer value : set){
                boolean b = true;
                for(int j = 0; j < taskNum;j++){
                    if (step[j][value] != 0){
                        b = false;
                        break;
                    }
                }
                if (b){
                    comp.add(value);
                }
            }
            stepCount++;
        }
        System.out.println(stepCount);
    }
 
}