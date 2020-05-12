import java.util.Scanner;

public class AliHelpingInnocentPeople{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String str = scan.next();

        int num1 = Integer.parseInt(String.valueOf(str.charAt(0)));
        int num2 = Integer.parseInt(String.valueOf(str.charAt(1)));
        int num3 = Integer.parseInt(String.valueOf(str.charAt(3)));
        int num4 = Integer.parseInt(String.valueOf(str.charAt(4)));
        int num5 = Integer.parseInt(String.valueOf(str.charAt(5)));
        int num6 = Integer.parseInt(String.valueOf(str.charAt(7)));
        int num7 = Integer.parseInt(String.valueOf(str.charAt(8)));

        char letter = str.charAt(2);

        int sum1 = num1 + num2;
        int sum2 = num3 + num4;
        int sum3 = num4 + num5;
        int sum4 = num6 + num7;

        if((sum1 % 2 == 0) && (sum2 % 2 == 0) && (sum3 % 2 == 0) && (sum4 % 2 == 0)){
            if((letter != 'A') && (letter != 'E') && (letter != 'I') && (letter != 'O') && (letter != 'U')){
                System.out.println("valid");
            } else {
                System.out.println("invalid");
            }
        } else {
            System.out.println("invalid");
        }
    }
}