public class Animal05 {
    int legs = 0;

    public int getLegs() {
        return this.legs;
    }

    public void printLegs(String msg) {
        System.out.println(msg + ": " + getLegs());
    }

    public static void main(String args[]) {
        System.out.println("Main function called...");

        Animal05 a = new Animal05();
        a.printLegs("Legs are");
        a.legs += 1;
        a.printLegs("Legs are");
    }
}
