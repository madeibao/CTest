

public class SignalTime {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        int m = Integer.parseInt(sc.nextLine());
        //坐标
        int site[] = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        //信号塔方阵
        int signal[][] = new int[n][m];
        for (int i = 0; i < n;i++){
            for (int j = 0; j < m;j++){
                signal[i][j] = sc.nextInt();
            }
        }
        minSignalTime(site,signal);
    }
 
    /**
     一次把map中已标记的坐标按上下左右查找，空值就放信号灯Map（重复）
     2值使用的次数  0 就是2ms 不然就是1ms
     * @param site 当前位置
     * @param signal 矩阵数据
     * @return
     */
    public static void minSignalTime(int site[],int signal[][]){
         int time = 0;
        //记录初始信息
        SingalInfo singalInfo = new SingalInfo();
        singalInfo.n = site[0];
        singalInfo.m = site[1];
        singalInfo.value = signal[site[0]][site[1]];
        List<SingalInfo> singalInfos = new ArrayList<>();
        singalInfos.add(singalInfo);
        //每一次循环能传递新号的灯塔
        Map<Map<Integer,Integer>,String>send = new HashMap<>();
        Map<Integer,Integer> m = new HashMap<>();
        m.put(site[0],site[1]);
        send.put(m,"true");
        List<Integer> times = new LinkedList<>();
        findSignal(signal,singalInfos,send,time,times);
        System.out.println(times.get(times.size()-2));
 
    }
 
    /**
     *
     * @param signal 新号灯矩阵
     * @param time 最小时间
     * @param singalInfos 当前已有的灯塔的遍历新号灯
     * @param send  是否已经点过了新号灯
     * @param times  取次数值
     */
    private static int findSignal(int[][] signal, List<SingalInfo> singalInfos, Map<Map<Integer,Integer>,String>send, int time,List<Integer> times) {
        List<SingalInfo> nowSingal = new ArrayList<>();
        for (int i = 0; i < singalInfos.size(); i++){
            int na = singalInfos.get(i).n;//列 x
            int ma = singalInfos.get(i).m;//行 y
            //遍历当前信号塔的四个方向
            //右
            if (singalInfos.get(i).m + 1 < signal.length){
                SingalInfo singalup = new SingalInfo();
                singalup.n = singalInfos.get(i).n;
                singalup.m = singalInfos.get(i).m + 1;
                singalup.value = signal[singalInfos.get(i).n][singalInfos.get(i).m+1];
                Map<Integer,Integer> m = new HashMap<>();
                m.put(singalup.n,singalup.m);
                //当前这批次会不会有A,B塔同时对一个灯塔发送信号
                abSendSignal(singalInfos, send, nowSingal, i, singalup, m);
            }
            //左
            if (singalInfos.get(i).m -1 >= 0){
                SingalInfo singaldown = new SingalInfo();
                singaldown.n = singalInfos.get(i).n;
                singaldown.m = singalInfos.get(i).m -1;
                singaldown.value = signal[singalInfos.get(i).n][singalInfos.get(i).m-1];
                Map<Integer,Integer> m = new HashMap<>();
                m.put(singaldown.n,singaldown.m);
                abSendSignal(singalInfos, send, nowSingal, i, singaldown, m);
 
            }
            //上
            if (singalInfos.get(i).n -1 >= 0){
                SingalInfo singalleft = new SingalInfo();
                singalleft.n = singalInfos.get(i).n -1;
                singalleft.m = singalInfos.get(i).m;
                singalleft.value = signal[singalInfos.get(i).n-1][singalInfos.get(i).m];
                Map<Integer,Integer> m = new HashMap<>();
                m.put(singalleft.n,singalleft.m);
                abSendSignal(singalInfos, send, nowSingal, i, singalleft, m);
 
 
            }
            //下
            if (singalInfos.get(i).n + 1 < signal.length){
                SingalInfo singalright = new SingalInfo();
                singalright.n = singalInfos.get(i).n + 1;
                singalright.m = singalInfos.get(i).m;
                singalright.value = signal[singalInfos.get(i).n+1][singalInfos.get(i).m];
                Map<Integer,Integer> m = new HashMap<>();
                m.put(singalright.n,singalright.m);
                abSendSignal(singalInfos, send, nowSingal, i, singalright, m);
 
            }
 
        }
        List<SingalInfo> nowSingalTemp = new ArrayList<>();
        //循环新加入的新号灯,会有重复的，去重且以A塔灯为主
        filterSignalB(nowSingal, nowSingalTemp,time,times,send);
        while (nowSingalTemp.size() != 0){
            return findSignal(signal,nowSingalTemp,send,time,times);
        }
        return time;
    }
 
    /**
     * A B信号塔发送信号之争
     * @param singalInfos  当前轮被点亮的灯塔（未传递新号给其它灯塔）
     * @param send 已经接收了新号加入的灯塔
     * @param nowSingal 下一轮将要被点亮的灯塔集合
     * @param i
     * @param singalup 下一轮的灯塔信息
     * @param m  下一轮的坐标
     */
    private static void abSendSignal(List<SingalInfo> singalInfos, Map<Map<Integer, Integer>, String> send, List<SingalInfo> nowSingal, int i, SingalInfo singalup, Map<Integer, Integer> m) {
        //下一轮中，重复被发新号的灯塔
        List<SingalInfo> repeat = new LinkedList<>();
        List<SingalInfo> addSi = new LinkedList<>();
        //还没遍历过的
        if (singalup.value!= 0 && (send.get(m) == null)){
            send.put(m,"true");
            nowSingal.add(singalup);
            if (singalInfos.get(i).value == 2){
                singalup.flag = true;
            }
        }
        if (send.get(m) != null) {
            for (int h = 0; h < nowSingal.size(); h++) {
                //下一轮的新号灯集合 存在A,B同时发送了新号
                if (nowSingal.get(h).flag && singalInfos.get(i).value == 1 && !send.get(m).equals("false")){
                    nowSingal.remove(h);
                    send.put(m,"true");
                    nowSingal.add(singalup);
                    break;
                }
            }
        }
    }
 
    /**
     * 查看下一将要传递的新号是否有B灯塔
     * @param nowSingal
     * @param nowSingalTemp
     * @param time
     * @param times
     * @param send
     * @return
     */
    private static int filterSignalB(List<SingalInfo> nowSingal, List<SingalInfo> nowSingalTemp, int time,List<Integer> times,Map<Map<Integer,Integer>,String>send) {
        Boolean endSignal = false;
        for (int k = 0; k < nowSingal.size(); k++) {
            SingalInfo sn = nowSingal.get(k);
            if (sn.flag && !endSignal) {
                if (times.size() > 0){
                    time = times.stream().max(Integer::compareTo).get() + 2;
                }else {
                    time+=2;
                }
                endSignal = true;
            }else if (!endSignal){
                if (times.size() > 0){
                    time = times.stream().max(Integer::compareTo).get() + 1;;
 
                }else {
                    time+=1;
                }
                endSignal = true;
            }
            nowSingalTemp.add(sn);
            Map<Integer,Integer> end = new HashMap<>();
            end.put(sn.n,sn.m);
            send.put(end,"false");
        }
        times.add(time);
        return time;
    }
 
    //用一个对象存储感觉更方便
    @Data
    static class SingalInfo {
        //列 || 下标
        int n;
        //行
        int m;
        //信号值
        int value;
        //是不是B信号灯给它传递的信号
        Boolean flag = false;
        //在上一轮中已经接收过新号了
        Boolean end = false;
 
        public SingalInfo(int n, int m, int value,Boolean flag,Boolean end) {
            this.n = n;
            this.m = m;
            this.value = value;
            this.flag = flag;
            this.end = end;
        }
 
        public SingalInfo() {
        }
    }
}