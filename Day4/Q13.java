package Day4;
import java.util.Scanner;

public class Q13 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the number of terms to generate: ");
        int n = sc.nextInt();
        
        int firstTerm = 0;
        int secondTerm = 1;
        
        System.out.println("Fibonacci Series:");
        
        int i = 1;
        while (i <= n) {
            System.out.print(firstTerm + " ");
            
            int nextTerm = firstTerm + secondTerm;
            firstTerm = secondTerm;
            secondTerm = nextTerm;
            
            i++;
        }
        sc.close();
    }
}
