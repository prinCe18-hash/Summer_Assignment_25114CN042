package Day5;
import java.util.Scanner;

public class Q17 {

    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter a positive integer: ");
        long number = scanner.nextLong();
        
        
        if (isPerfectNumber(number)) {
            System.out.println(number + " is a perfect number.");
        } else {
            System.out.println(number + " is NOT a perfect number.");
        }
        
        scanner.close();
    }
    public static boolean isPerfectNumber(long num) {
        if (num <= 0) {
            return false;
        }
        long sum = 0;
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                sum += i; 
            }
        }
        return sum == num;
    }
}
