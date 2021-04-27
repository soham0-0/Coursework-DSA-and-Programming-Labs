abstract class Monster {}

class Vampire extends Monster {}

class Werewolf extends Monster {}

class Zombie extends Monster {}

public class p11_abstract_monster {
    public static void main(String[] args) {
        Monster[] arr = new Monster[6];
        arr[0] = new Vampire();
        arr[1] = new Werewolf();
        arr[2] = new Werewolf();
        arr[3] = new Vampire();
        arr[4] = new Zombie();
        arr[5] = new Zombie();

        for (int i = 0; i < arr.length; ++i) {
            System.out.println((i + 1) + ". " + arr[i].getClass().getName());
        }
    }
}
