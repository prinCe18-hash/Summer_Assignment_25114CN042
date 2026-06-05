package Day5;
import java.util.Scanner;

public class Q20 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter a positive integer: ");
        long number = scanner.nextLong();
        
        if (number <= 1) {
            System.out.println("Numbers less than or equal to 1 do not have prime factors.");
        } else {
            long largestFactor = findLargestPrimeFactor(number);
            System.out.println("The largest prime factor of " + number + " is: " + largestFactor);
        }
        
        scanner.close();
    }
    public static long findLargestPrimeFactor(long num) {
        long maxPrime = -1;
        while (num % 2 == 0) {
            maxPrime = 2;
            num /= 2;
        }
        for (long i = 3; i * i <= num; i += 2) {
            while (num % i == 0) {
                maxPrime = i;
                num /= i;
            }
        }
        if (num > 2) {
            maxPrime = num;
        }

        return maxPrime;
    }
}
