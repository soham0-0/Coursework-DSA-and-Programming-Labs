class M {
    float m_float;
    String m_string;
    M(float x, String y) {
        m_float = x;
        m_string = y;
        System.out.println("M constructor called!");
    }
    void display() {
        System.out.println("float variable in M is " + m_float);
        System.out.println("String variable in M is " + m_string);
    }
}

class N extends M {
    double n_double;
    N(double d, float x, String y) {
        super(x, y);
        n_double = d;
        System.out.println("N constructor called!");
    }
    void display() {
        super.display();
        System.out.println("double variable in N is " + n_double);
    }
}

public class p6_class_inheritance_hierarchy {
    public static void main(String args[]) {
        N ob = new N(11.243, 12.9f, "Admiral");
        ob.display();
    }
}
