public class p2_primes {
    public static void main(String args[]) {
        System.out.println("Primes between 100 and 200 are:");
        for(int i = 100; i < 200; ++i) {
            boolean isPrime = true;
            for(int j = 2; j <= (int) Math.sqrt(i); ++j) if (i % j == 0) {
                isPrime = false;
                break;
            }
            if(isPrime) System.out.println(i);
        }
    }
}
