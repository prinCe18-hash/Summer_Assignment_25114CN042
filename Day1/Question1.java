import java.util.Scanner;

public class Question1{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a positive number:-");
        int N = sc.nextInt();
 // Using formula
        int sumFormula = N * (N + 1) / 2;
 
        System.out.println("Sum using formula: " + sumFormula);
        

    }
}
