


public class 流水线 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int line = sc.nextInt();
        int task = sc.nextInt();
        List<Integer> taskList = new ArrayList<>();
        for(int i = 0; i < task;i++){
            taskList.add(sc.nextInt());
        }
        
        //按作业花费时间从小到大排序
        Collections.sort(taskList);
        //（滑动窗口）最后的3个正在进行的作业以最后一个值为准 + 倒数第四个用的时间
        int time = taskList.get(taskList.size() -1 - line) + taskList.get(taskList.size() -1);
        System.out.println(time);
    }
}