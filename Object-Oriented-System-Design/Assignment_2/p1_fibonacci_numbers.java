public class p1_fibonacci_numbers {
    public static void main(String args[]) {
        int prev = 0, cur = 1;
        System.out.println("First 15 fibonacci numbers:");
        for(int i = 0; i < 15; ++i) {
            if(i == 0) System.out.print(prev + " ");
            else if(i == 1) System.out.print(cur + " ");
            else {
                cur = prev + cur;
                prev = cur - prev;
                System.out.print(cur + " ");
            }
        }
        System.out.println();
    }
}