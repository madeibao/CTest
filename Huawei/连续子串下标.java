

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);    
        System.out.println(getResult(sc.nextLine(),sc.nextLine()));
    }
    public static String getResult(String str, String subStr) {
        if(str.length()<subStr.length()) {
            return "No";
        }
        int index = str.indexOf(subStr);
        if(index==-1) {
            return "No";
        }
        else {
            return index+1+"";
        }
    }
}


python 写法：


s = input()
substr = input()

def getResult():
    if(len(s)<len(subStr)):
        return "No"
    
    index = s.find(subStr)
    if(index == -1):
        return "No"
    else:
        return index+1

print(getResult())
