abstract class Fruit {
    String color, name;
    Fruit(String c, String n) {
        color = c;
        name = n;
    }
    @Override   
    public String toString() {
        return String.format(name + " has color " + color);
    }
}

class Apple extends Fruit {
    Apple() {
        super("red", "Apple");
    }
}

class Banana extends Fruit {
    Banana() {
        super("yellow", "Banana");
    }
}

class Orange extends Fruit {
    Orange() {
        super("orange", "Orange");
    }
}

class Strawberry extends Fruit {
    Strawberry() {
        super("red", "Strawberry");
    }
}

public class p9_abstract_fruit {
    public static void main(String args[]) {
        Apple a = new Apple();
        Banana b = new Banana();
        Orange c = new Orange();
        Strawberry d = new Strawberry();
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.println(d);
    }
}
