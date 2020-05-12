import java.util.Scanner;

public class BookOfPotionMaking{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        long number = scan.nextLong();
        int counter = 10;
        int sum = 0;
        int remainder = 0;
        while(number != 0){
            remainder = (int) (number % 10);
            number = number / 10;
            sum = sum + counter * remainder;
            counter--;
        }

        if(sum % 11 == 0){
            System.out.println("Legal ISBN");
        } else {
            System.out.println("Illegal ISBN");
        }
    }
}