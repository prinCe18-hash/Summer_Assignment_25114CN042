package Day4;
import java.util.Scanner;

public class Q15 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter a number to check: ");
        int number = scanner.nextInt();
        
        int originalNumber = number;
        int result = 0;
        
        int numberOfDigits = String.valueOf(number).length();
        
        while (number != 0) {
            int remainder = number % 10;
            
            result += Math.pow(remainder, numberOfDigits);
            
            number /= 10;
        }
        
        if (originalNumber == result) {
            System.out.println(originalNumber + " is an Armstrong number.");
        } else {
            System.out.println(originalNumber + " is not an Armstrong number.");
        }
        
        scanner.close();
    }
}
