import java.util.Scanner;

public class DigitProblem{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String number = scan.next();
        int k = scan.nextInt();

        int start = 0;
        while(k != 0){
            number = number.substring(0,start) + "9" + number.substring(start + 1, number.length());
            start++;
            k--;
        }

        System.out.println(number);
    }
}