import java.util.*;

public class CrazyBits{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int testcases = scan.nextInt();

        int number = 0;
        for(int i = 0;i < testcases;i++){
            number = scan.nextInt();
            String numberBinary = "";

            while(number != 0){
                numberBinary = (number % 2) + numberBinary;
                number /= 2;
            }

            int countSetBits = 0;
            for(int j = numberBinary.length() - 1;j >= 0;j--){
                if(numberBinary.charAt(j) == '0'){
                    numberBinary = numberBinary.substring(0,j) + "1" + numberBinary.substring(j+1,numberBinary.length());
                    break;
                }
                countSetBits++;
            }

            if(countSetBits == numberBinary.length()){
                numberBinary = "1" + numberBinary;
            }

            long decimal = 0;
            long base = 1;
            for(int j = numberBinary.length() - 1;j >= 0;j--){
                decimal = decimal + (Integer.parseInt(String.valueOf(numberBinary.charAt(j)))) * base;
                base *= 2;
            }

            System.out.println(decimal);
        }
    }
}