package Day4;
import java.math.BigInteger;
import java.util.Scanner;

public class Q14 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the n position to find that Fibonacci number: ");
        int n = scanner.nextInt();
        
        // Base cases: if n is 1, return 0. If n is 2, return 1.
        if (n == 1) {
            System.out.println("The 1st Fibonacci term is: 0");
        } else if (n == 2) {
            System.out.println("The 2nd Fibonacci term is: 1");
        } else {
            BigInteger firstTerm = BigInteger.ZERO;
            BigInteger secondTerm = BigInteger.ONE;
            BigInteger nthTerm = BigInteger.ZERO;
            
            // Loop starts from 3 because first two terms are already known
            for (int i = 3; i <= n; i++) {
                nthTerm = firstTerm.add(secondTerm);
                firstTerm = secondTerm;
                secondTerm = nthTerm;
            }
            
            System.out.println("The " + n + "th Fibonacci term is: " + secondTerm);
        }
        
        scanner.close();
    }
}
