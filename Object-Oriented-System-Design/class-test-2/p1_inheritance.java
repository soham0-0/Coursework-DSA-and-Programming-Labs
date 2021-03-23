class Fish {
    double length;
    String colour, scaleType;
    Fish(double len, String color, String sType) {
        length = len;
        colour = color; 
        scaleType = sType;
    }
    void display() {
        System.out.println("Length (in m): " + length);
        System.out.println("Colour: " + colour);
        System.out.println("Scale Type: " + scaleType);
    }
}

class Shark extends Fish {
    String name, uniqueFeature;
    Shark(double len, String color, String sType, String n, String uf) {
        super(len, color, sType);
        name = n;
        uniqueFeature = uf;
    }
    void display () {
        System.out.println("Name: " + name);
        System.out.println("Unique Feature: " + uniqueFeature);
    }
}

public class p1_inheritance {
    public static void main(String[] args) {
        Shark s = new Shark(6.1, "grey", "tiny and tough", "Sharko", "Sharp Teeth");
        s.display();
    }
}

