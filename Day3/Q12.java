package Day3;
import java.util.Scanner;

public class Q12 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter first number: ");
        int num1 = sc.nextInt();
        System.out.print("Enter second number: ");
        int num2 = sc.nextInt();
        
        // Handle zero and negative numbers
        int a = Math.abs(num1);
        int b = Math.abs(num2);
        
        if (a == 0 || b == 0) {
            System.out.println("The LCM of " + num1 + " and " + num2 + " is: 0");
        } else {
            // Find GCD using a loop inside main
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            int gcd = a; // At the end of the loop, 'a' holds the GCD
            
            // Calculate LCM using the single-method variables
            int lcm = (Math.abs(num1) / gcd) * Math.abs(num2);
            
            System.out.println("The LCM of " + num1 + " and " + num2 + " is: " + lcm);
        }
    }
}
