class Circle {
    double radius, cx, cy;
    Circle(double r) {
        cx = 0;
        cy = 0;
        radius = r;
    }
    Circle(double r, double x, double y) {
        cx = x;
        cy = y;
        radius = r;
    }
    void display() {
        System.out.println("Radius: " + radius);
        System.out.println("Centre x-coordinate: " + cx);
        System.out.println("Centre y-coordinate: " + cy);
    }
}

public class p4_circle_with_two_constructors {
    public static void main(String args[]) {
        Circle c1 = new Circle(10.2), c2 = new Circle(12.1, 1.0, 2.5);
        System.out.println("Circle 1:");
        c1.display();
        System.out.println("Circle 2:");
        c2.display();
    }
}