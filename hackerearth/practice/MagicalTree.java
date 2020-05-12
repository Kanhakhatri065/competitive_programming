import java.util.*;

public class MagicalTree{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int size = scan.nextInt();

        int []total = new int[size];
        for(int i = 0;i < size;i++){
            String inputStr = scan.next();

            int sum = Integer.parseInt(String.valueOf(inputStr.charAt(0)));
            int temp = 0;
            char operation = '.';
            
            for(int j = 1;j < inputStr.length();j++){
                if(inputStr.charAt(j) >= 48 && inputStr.charAt(j) <= 57){
                    temp = Integer.parseInt(String.valueOf(inputStr.charAt(j)));

                    if(operation == '+'){
                        sum += temp;
                    } else if(operation == '-'){
                        sum -= temp;
                    }
                    
                } else {
                    operation = inputStr.charAt(j);
                }
            }

            total[i] = sum;
        }

        Arrays.sort(total, 0, total.length);

        System.out.println(total[size -1]);        
    }
}