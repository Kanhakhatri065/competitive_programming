import java.util.Scanner;

public class TeddyTweety{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int number = scan.nextInt();

        if(number % 3 == 0){
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}