package Day3;
import java.util.Scanner;
public class Q10 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter lower bound: ");
        int lower = sc.nextInt();
        System.out.print("Enter upper bound: ");
        int upper = sc.nextInt();
        
        System.out.println("Prime numbers between " + lower + " and " + upper + " are:");
        
        for (int i = lower; i <= upper; i++) {
            // Checking if the  number i is prime
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
        }
    }

    //  method to check if a single number is prime
    public static boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false; // factor is present, not prime
            }
        }
        return true; // No factors present, it is prime
    }
}

