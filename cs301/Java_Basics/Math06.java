public class Math06 {
    public double sqrt(int x, double guess) {
        System.out.println("Calculating Square root of " + x + " Starting with guess: " + guess);
        return 1.0;
    }

    public double sqrt(int x){
        double guess = 1.0;
        return sqrt(x, guess);
    }

    public static void main(String args[]) {
        System.out.println("Main function called....");
        Math06 m = new Math06();
        m.sqrt(36);

    }
}
