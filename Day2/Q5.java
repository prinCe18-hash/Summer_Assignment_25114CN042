package Day2;
import java.util.Scanner;

public class Q5 {
    public static void main(String[] args) {
       
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter any number: ");
        long number = scanner.nextLong();
        
        long tempNumber = Math.abs(number);
        long sum = 0;       
        while (tempNumber != 0) {
            long lastDigit = tempNumber % 10; 
            sum += lastDigit;                 
            tempNumber /= 10;                
        }
         System.out.println("The sum of the digits of " + number + " is: " + sum);
         scanner.close();
    }
}
