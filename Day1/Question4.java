import java.util.Scanner;
public class Question4 {
    public static void main(String[] args){
       Scanner sc = new Scanner(System.in);
       System.out.print("Enter a number:- ");
        int N = sc.nextInt();
        int count = 0;
        int temp = N;

        // For zero separately
        if (temp == 0) {
            count = 1;
        } else {
            // Counting digits by dividing by 10
            while (temp != 0) {
                temp /= 10;
                count++;
            }
        }

       
        System.out.println("Number of digits in " + N + " is: " + count);


    }
    
}
