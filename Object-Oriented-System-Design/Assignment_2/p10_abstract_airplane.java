abstract class Airplane {
    int capacity;
    String serial, type;
    Airplane(int cap, String ser) {
        capacity = cap;
        serial = ser;
    }
    @Override
    public String toString() {
        return String.format("Serial " + serial + " of type " + type + " has capacity " + capacity);
    }
}

class B747 extends Airplane {
    B747(int cap, String ser) {
        super(cap, ser);
        type = "B747";
    }
}

class B757 extends Airplane {
    B757(int cap, String ser) {
        super(cap, ser);
        type = "B757";
    }
}

class B767 extends Airplane {
    B767(int cap, String ser) {
        super(cap, ser);
        type = "B767";
    }
}

public class p10_abstract_airplane {
    public static void main(String[] args) {
        B747 a1 = new B747(416, "1");
        B757 a2 = new B757(200, "2");
        B767 a3 = new B767(216, "3");
        System.out.println(a1);
        System.out.println(a2);
        System.out.println(a3);
    }
    
}
