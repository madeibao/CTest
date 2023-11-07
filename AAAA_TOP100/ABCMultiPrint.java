

public class ABCMultiPrint {
    private Object lock = new Object();
    int num = 0;


    public void printABC(String name,int no) {
        for(int i=0;i<10;i++) {
            synchronized (lock) {
                while (num%3!=no) {
                    try {
                        lock.wait();
                    }
                    catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                ++num;
                System.out.println(name +" "+ no);
                lock.notifyAll();
            }
        }
    }

    public static void main(String[] args) {

        ABCMultiPrint m = new ABCMultiPrint();
        new Thread(()-> {
            m.printABC("A",0);
        }).start();
        new Thread(()-> {
            m.printABC("B",1);
        }).start();
        new Thread(()-> {
            m.printABC("C",2);
        }).start();
    }
}
