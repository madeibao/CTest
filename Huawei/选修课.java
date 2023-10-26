

public class OptionalCourse {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] one = sc.nextLine().split(";");
        String [] two = sc.nextLine().split(";");
        student(one,two);
    }
 
    public static void student(String[] one,String [] two){
        List<StudentInfo> oneStudentInfos = new ArrayList<>();
        List<StudentInfo> twoStudentInfos = new ArrayList<>();
        List<StudentInfo> endStudentInfos = new ArrayList<>();
        Set<String> schoolInfo = new HashSet<>();
        //2门成绩的id跟分数都存在List对象中
        for (String s : one){
            String [] one1 = s.split(",");
            StudentInfo st = new StudentInfo(one1[0],Integer.valueOf(one1[1]));
            oneStudentInfos.add(st);
        }
        for (String s : two){
            String [] two2 = s.split(",");
            StudentInfo st = new StudentInfo(two2[0],Integer.valueOf(two2[1]));
            twoStudentInfos.add(st);
        }
        //将2门都存在成绩的学生信息统计
        for (int i = 0; i < oneStudentInfos.size(); i++){
            for (int j = 0; j < twoStudentInfos.size(); j++){
                if (oneStudentInfos.get(i).id.equals(twoStudentInfos.get(j).id)){
                    int score = oneStudentInfos.get(i).score + twoStudentInfos.get(i).score;
                    StudentInfo st = new StudentInfo(oneStudentInfos.get(i).id,score);
                    endStudentInfos.add(st);
                    //截取开头5位数
                    String schoolId = oneStudentInfos.get(i).id.substring(0,5);
                    schoolInfo.add(schoolId);
                }
            }
        }
        if (endStudentInfos.size() == 0) {
            System.out.println("NULL");
            return;
        }
        //将set开头5位数排序后存在List中
        List<String> schoolInfos = schoolInfo.stream()
                .sorted(Comparator.naturalOrder())
                .collect(Collectors.toList());
        compareStudent(endStudentInfos,schoolInfos);
    }
 
    /**
     * 按照存储的开头5位数进行分类输出
     * @param endStudentInfos
     * @param schoolInfo
     */
    public static void compareStudent(List<StudentInfo> endStudentInfos,List<String> schoolInfo){
        Collections.sort(endStudentInfos,new StudentInfo());
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < schoolInfo.size();i++){
            System.out.println(schoolInfo.get(i));
            for (int j = 0; j < endStudentInfos.size(); j++){
                if (endStudentInfos.get(j).id.substring(0,5).equals(schoolInfo.get(i))){
                   sb.append(endStudentInfos.get(j).id).append(";");
                }
            }
            System.out.println(sb.toString().substring(0,sb.length()-1));
            sb.setLength(0);
        }
    }
 

    static class StudentInfo implements Comparator<StudentInfo> {
        String id;
        int score;
 
        public StudentInfo(String id, int score) {
            this.id = id;
            this.score = score;
        }
 
        public StudentInfo() {
        }
 
        @Override
        public int compare(StudentInfo o1, StudentInfo o2) {
            return Integer.valueOf(o1.id) - Integer.valueOf(o2.id);
        }
    }
}