import java.util.Vector;

public class Runner11 {

    public void printVector(Vector<String> v) {
        for (int i = 0; i < v.size(); i++) {
            System.out.println(v.get(i));
        }
    }

    public void intVectorTest() {
        Vector<String> vs = new Vector<String>();
        vs.add("First");
        vs.add("Second");
        vs.add("Something");

        printVector(vs);
        System.out.println(vs);
    }

    public static void main(String[] args) {
        Runner11 r = new Runner11();
        r.intVectorTest();
    }
}
