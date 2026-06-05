package Day5;
import java.util.Scanner;

public class Q18 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter a positive integer: ");
        int number = scanner.nextInt();
        
        if (isStrongNumber(number)) {
            System.out.println(number + " is a strong number.");
        } else {
            System.out.println(number + " is NOT a strong number.");
        }
        
        scanner.close();
    }
    public static boolean isStrongNumber(int num) {
        if (num <= 0) {
            return false;
        }

        int originalNumber = num;
        int sum = 0;

        while (num > 0) {
            int digit = num % 10;       
            sum += getFactorial(digit);  
            num = num / 10;            
        }
        return sum == originalNumber;
    }
    public static int getFactorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
}
