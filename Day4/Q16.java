package Day4;
import java.util.Scanner;

public class Q16 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter starting number: ");
        int start = scanner.nextInt();
        System.out.print("Enter ending number: ");
        int end = scanner.nextInt();
        
        System.out.println("Armstrong numbers between " + start + " and " + end + " are:");
        
        for (int i = start; i <= end; i++) {
            int number = i;
            int result = 0;
            
            int numberOfDigits = String.valueOf(number).length();
            
            while (number != 0) {
                int remainder = number % 10;
                result += Math.pow(remainder, numberOfDigits);
                number /= 10;
            }
            
            if (result == i) {
                System.out.print(i + " ");
            }
        }
        
        System.out.println(); 
        scanner.close();
    }
}
