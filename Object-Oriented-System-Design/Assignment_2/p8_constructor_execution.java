class S1 {
    int s1;
    S1(int val) {
        System.out.println("S1 constructor called");
        s1 = val;
    }
}

class T1 extends S1 {
    int t1;
    T1(int val1, int val2 ) {
        super(val2);
        System.out.println("T1 constructor called");
        t1 = val1;
    }
}

class U1 extends T1{
    int u1;
    U1(int val1, int val2, int val3) {
        super(val2, val3);
        System.out.println("U1 constructor called");
        u1 = val1;
    }
}

public class p8_constructor_execution {
    public static void main(String[] args) {
        U1 u = new U1(32, 51, 228);
    }
}
