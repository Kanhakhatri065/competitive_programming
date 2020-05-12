import java.util.Scanner;

public class SevenSegmentDisplay{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int display[] = {6,2,5,5,4,5,6,3,7,6};

        int testcases = scan.nextInt();

        int total_matchsticks;
        for(int i = 0;i < testcases;i++){
            total_matchsticks = 0;
            long number = scan.nextLong();

            int remainder = 0;

            if(number == 0){
                total_matchsticks = 6;
            } else {
                while(number != 0){
                    remainder = (int) (number % 10);
                    total_matchsticks = total_matchsticks + display[remainder];
                    number = number / 10;
                }
            }
            
            long output = 0;
            if(total_matchsticks % 2 == 0){
                while(total_matchsticks != 0){
                    total_matchsticks -= 2;
                    output = output * 10 + 1;
                }
            } else {
                total_matchsticks -= 3;
                output = 7;
                while(total_matchsticks != 0){
                    total_matchsticks -= 2;
                    output = output * 10 + 1;
                }
            }
            System.out.println(output);
        }
    }
}