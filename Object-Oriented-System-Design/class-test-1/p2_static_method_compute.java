public class p2_static_method_compute {
    public static void main(String[] args) {
        test.Compute(98, 91, 88); // Marks obtained as params
        test.Compute(80, 80, 86);
        test.Compute(98, 90, 100);
        test.Compute(99, 98, 98);
        test.Compute(88, 82, 79);
    }
}

class test {
    static void Compute(double physics, double chemistry, double mathematics) {
        double maximum_marks = 100; // Change this for different max marks
        System.out.println("Percentage: " + (physics + chemistry + mathematics) * 100 / (3 * maximum_marks) + " %");
    }
}