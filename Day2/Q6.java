package Day2;
import java.util.Scanner;
public class Q6 {
public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.println("Write a number to reverse:");
    int num = sc.nextInt();
        
        int originalNum = num; 
        int reversedNum = 0;
        
        while (num != 0) {
            int lastDigit = num % 10;                
            reversedNum = reversedNum * 10 + lastDigit; 
            num = num / 10;                         
        }
        
        System.out.println("Original Number: " + originalNum);
        System.out.println("Reversed Number: " + reversedNum);
        
        sc.close();
    }
}

