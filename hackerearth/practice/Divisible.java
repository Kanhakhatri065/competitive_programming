import java.util.Scanner;

public class Divisible{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int size = scan.nextInt();

        String []arr = new String[size];
        
        for(int i = 0;i < arr.length;i++){
            arr[i] = scan.next();
        }

        String numStr = "";
        for(int i = 0;i < (arr.length / 2);i++){
            numStr = numStr + arr[i].charAt(0);
        }

        for(int i = (arr.length / 2); i < arr.length;i++){
            numStr = numStr + arr[i].charAt(arr[i].length() - 1);
        }

        long sumOddDigits = 0;
        for(int i = 1;i < numStr.length();i = i + 2){
            sumOddDigits = sumOddDigits + Long.parseLong(String.valueOf(numStr.charAt(i)));
        }

        long sumEvenDigits = 0;
        for(int i = 0;i < numStr.length();i = i + 2){
            sumEvenDigits = sumEvenDigits + Long.parseLong(String.valueOf(numStr.charAt(i)));
        }

        if((sumOddDigits - sumEvenDigits) % 11 == 0){
            System.out.println("OUI");
        } else {
            System.out.println("NON");
        }
        
    }
}