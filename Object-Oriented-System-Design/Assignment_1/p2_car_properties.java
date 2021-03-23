public class p2_car_properties {
    public static void main(String args[]) {
        Car roadrunnerGtx = new Car("Convertible", "Scorch Red", "Plymouth", "TorqueFlite automatic transmission", 11.2, 3635.0);
        roadrunnerGtx.displayProperties();
    }
}

class Car {
    String type, colour, make, gearType;
    double mileage, cost;
    Car(String type, String colour, String make, String gearType, double mileage, double cost) {
        this.type = type;
        this.colour = colour;
        this.make = make;
        this.gearType = gearType;
        this.cost = cost;
        this.mileage = mileage;
    }
    void displayProperties(){
        System.out.println("Type: " + type);
        System.out.println("Make: " + make);
        System.out.println("Colour: " + colour);
        System.out.println("Gear Type: " + gearType);
        System.out.println("Mileage (in MPG): " + mileage);
        System.out.println("Cost (in dollars): " + cost);
    }
}