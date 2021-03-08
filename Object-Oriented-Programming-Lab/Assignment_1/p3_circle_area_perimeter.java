public class p3_circle_area_perimeter {
    public static void main(String[] args) {
        Circle c1 = new Circle(5);
        double area1 = c1.computeArea(), perimeter1 = c1.computePerimeter();
        System.out.println("Area: " + area1);
        System.out.println("Perimeter: " + perimeter1);
    }
}

class Circle {
    double radius;
    Circle(double radius) {
        this.radius = radius;
    }
    double computeArea(){
        return Math.PI * radius * radius;
    }
    double computePerimeter(){
        return Math.PI * 2 * radius;
    }
}