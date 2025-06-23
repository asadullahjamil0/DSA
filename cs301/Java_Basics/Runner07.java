abstract class Polygon {
    int numSides;

    public Polygon() {
        this.numSides = 0;
    }

    public Polygon(int numSides) {
        this.numSides = numSides;
    }

    public abstract double getArea();
}

class Rectangle extends Polygon {
    public Rectangle() {
        super(4);
    }

    double length;
    double width;

    public void setSides(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public double getArea() {
        return this.length * this.width;
    }
}

public class Runner07 {
    public static void main(String args[]) {
        System.out.println("Main function called...");

        // Polygon a = new Polygon(4);
        // System.out.println("Area of polygon: " + a.getArea());

        Rectangle r = new Rectangle();
        System.out.println("Sides of Rectangle: " + r.numSides);

        r.setSides(4.0, 4.0);
        System.out.println("Area of Rectangle: " + r.getArea());
    }

}
