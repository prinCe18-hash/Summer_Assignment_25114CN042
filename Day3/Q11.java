package Day3;
import java.util.Scanner;

public class Q11 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter first number: ");
        int num1 = sc.nextInt();
        System.out.print("Enter second number: ");
        int num2 = sc.nextInt();
        
       
        int gcd = findGCD(num1, num2);
        
        System.out.println("The GCD of " + num1 + " and " + num2 + " is: " + gcd);
    }

    
    public static int findGCD(int a, int b) {
       
        a = Math.abs(a);
        b = Math.abs(b);
        
        while (b != 0) {
            int temp = b;
            b = a % b; // Getting the remainder
            a = temp;  
        }
        return a;
    }
}