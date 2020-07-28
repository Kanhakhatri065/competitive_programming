import java.util.Scanner;

public class Dice{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String input = scan.next();

        int sum = 0;
        int exception = 0;
        for(int i = 0;i < input.length();i++){
            int number = Integer.parseInt(String.valueOf(input.charAt(i)));

            if(number < 6){
                sum++;
            }

            if((i == input.length() - 1) || (i == input.length() - 2)){
                if(number == 6){
                    exception++;
                }
            }
        }

        if(exception == 2){
            System.out.println("-1");
        } else {
            System.out.println(sum);
        }
    }
}