class G {
    static int x = 100;
    int get() {
        return x;
    }
}

class H extends G {
    int x = 200;
    void display() {
        System.out.println("x of class H: " + x);
        System.out.println("x of class G: " + super.get());
    }
}

public class p7_hidden_variables {
    public static void main(String args[]) {
        H h1 = new H();
        h1.display();
    }
}
