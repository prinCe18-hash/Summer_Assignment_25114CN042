package Day3;
import java.util.Scanner;

public class Q9{
    public static void main(String[] args){
         Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        
        boolean isPrime = true;
        
        // Numbers that are less than or equal to 1 are not prime numbers.
        if (num <= 1) {
            isPrime = false;
        } else {
            
            for (int i = 2; i <= Math.sqrt(num); i++) {
                if (num % i == 0) {
                    isPrime = false; 
                    break;          
                }
            }
        }
        
        if (isPrime) {
            System.out.println(num + " is a prime number.");
        } else {
            System.out.println(num + " is not a prime number.");
        }
    }
}
