import java.util.Scanner;

public class Question2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number for which we have to print multiplication table:-" );
        int N = sc.nextInt();
// Using formula
        System.out.println("Multiplication Table of" + N +":");
        for (int i = 1; i <= 10; i++) {
            System.out.println(N + "x" + i + "=" + (N * i));
        }
    }
    
}


       