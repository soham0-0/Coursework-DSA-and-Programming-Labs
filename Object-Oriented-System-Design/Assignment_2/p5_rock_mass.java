import java.util.Random;

class Rock {
    int mass;
    Rock() {
        Random r = new Random();
        mass = 1 + r.nextInt(10);
    }
}

public class p5_rock_mass {
    public static void main(String args[]) {
        Rock rocks[] = new Rock[10];
        int total = 0;
        for(int i = 0; i < 10; ++i) {
            rocks[i] = new Rock();
            System.out.println("Mass of Rock " + (i + 1) + ": " + rocks[i].mass);
            total += rocks[i].mass;
        }
        System.out.println("Total mass of rocks:" + total);
    }
}
