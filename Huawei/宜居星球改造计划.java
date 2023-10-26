

public class PlantaryModification {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[][] value = new String[8][8];
        int i = 0;
        Boolean NA = false;
        int countDay = 0;
        while (sc.hasNextLine()){
            String in = sc.nextLine();
            if (in.isEmpty()){
                break;
            }
            String[] valueLine = in.split(" ");
            for (int j = 0; j<valueLine.length;j++){
                //检查是否有死亡区
                if (valueLine[j].equals("NA")){
                    NA = true;
                }
                value[i][j] = valueLine[j];
            }
            i++;
        }
        //有死亡区直接返回-1
        if (NA){
            countDay = -1;
            System.out.println(countDay);
            return;
        }
        //取出null无效占用空间
       /* String [][] filterValue = Arrays.stream(value)
                .flatMap(Arrays::stream)
                .filter(Objects::nonNull)
                .toArray(String[][]::new);*/
        Set<YN> yns = new HashSet<>();
         countDay = countDay(value,countDay,0,0,yns);
        System.out.println(countDay);
    }
 
    /**
     * @param value
     * @param countDay
     * @return
     */
    public static int countDay(String[][]value,int countDay,int m,int n,Set<YN> yns){
        //统计所有的YES值，后续操作,相当于初始化，只执行一次
        if (yns.isEmpty()) {
            for (int i = m; i < value.length; i++) {
                for (int j = n; j < value[i].length; j++) {
                    if (StringUtils.isEmpty(value[i][j])) {
                       break;
                    }else if (value[i][j].equals("YES")) {
                        YN yn = new YN(i, j);
                        yns.add(yn);
                    }
                }
            }
        }
        //每次刷新一天后看是否还存在NO值
        Boolean end = true;
        while (end) {
            for (int i = m; i < value.length; i++) {
                for (int j = n; j < value[i].length; j++) {
                    if (!StringUtils.isEmpty(value[i][j]) && value[i][j].equals("NO")) {
                        countDay++;
                        noToYes(value, yns, countDay, m, n);
                    }
                }
            }
            end = false;
        }
        return countDay;
    }
    public static void noToYes(String[][]value,Set<YN> yns,int countDay,int m,int n){
        Set<YN> ynsA = new HashSet<>();
        for (YN yn : yns){
            //上下左右
            UDLF(value, ynsA, yn);
        }
        //合并(每一天存量更新)
        for (YN yn : ynsA){
            yns.add(yn);
        }
    }
 
    private static void UDLF(String[][] value, Set<YN> ynsA, YN yn) {
        YN upYn = new YN(yn.m,yn.n-1);
        move(value,ynsA,upYn);
        YN domw = new YN(yn.m,yn.n+1);
        move(value,ynsA,domw);
        YN left = new YN(yn.m-1,yn.n);
        move(value,ynsA,left);
        YN right = new YN(yn.m+1,yn.n);
        move(value,ynsA,right);
    }
 
    public static void move(String[][] value, Set<YN> ynsA,YN yn){
        if (yn.m < value.length && yn.m >= 0 && yn.n < value[yn.m].length && yn.n >=0){
            if (!StringUtils.isEmpty(value[yn.m][yn.n]) && value[yn.m][yn.n].equals("NO")){
                value[yn.m][yn.n] = "YES";
                YN ynA = new YN(yn.m, yn.n);
                ynsA.add(ynA);
            }
        }
    }
 
    static class YN{
        int m;
        int n;
 
        public YN(int m, int n) {
            this.m = m;
            this.n = n;
        }
    }
}