import java.util.*;
class Solution{

    static int factorial(int number){
        if(number == 0 || number == 1){
            return 1;
        }
        return number * factorial(number - 1);
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int testcases = scan.nextInt();
        for(int i = 0;i < testcases;i++){
            int number = scan.nextInt();

            System.out.println(factorial(number));
        }
    }
}