public class Animal02 {
    int legs = 4;

    public int get_legs() {
        return this.legs;
    }

    void constructs_test() {
        int x = 5;
        if (x == 5) {
            System.out.println("X is equal to 5");
        }
        for (int i = 0; i < 5; i++) {
            System.out.println("Looping: " + i);
        }
    }

    public static void main(String args[]) {
        System.out.println("Main function called....");
        Animal02 a = new Animal02();
        System.out.print("Legs:" + a.legs + "\n");
        System.out.print("Legs from method:" + a.get_legs());

        a.constructs_test();
    }
}