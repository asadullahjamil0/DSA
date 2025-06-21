public class Student03 {
    static int num = 0;
    int rollNo;

    public static void main(String args[]) {
        System.out.println("Main function called...");
        Student03 s1 = new Student03();
        Student03 s2 = new Student03();
        // s1.rollNo = 123;
        // s2.rollNo = 432;

        System.out.println("Student03.num = " + Student03.num);
        Student03.num += 1;
        System.out.println("Student03.num = " + Student03.num);

        System.out.println("\n s1 roll no = " + s1.rollNo);
        System.out.println("\n s2 roll no = " + s2.rollNo);
    }
}
