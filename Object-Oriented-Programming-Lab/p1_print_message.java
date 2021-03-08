public class p1_print_message {
    public static void main(String args[]) {
        message object = new message();
        object.display();
    }
}

class message {
    void display() {
        System.out.println("Welcome to Java programming world");
    }
}