import java.util.Scanner;

public class AdditionAintSimple{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int testcases = scan.nextInt();
        for(int i = 0;i < testcases;i++){
            String input = scan.next();

            String reverseInput = "";
            for(int j = input.length()-1;j>=0;j--){
                reverseInput = reverseInput + input.charAt(j);
            }

            String output = "";
            for(int j = 0;j < input.length();j++){
                int inputCharASCII = (int)input.charAt(j);
                int reverseInputCharASCII = (int)reverseInput.charAt(j);

                int outputCharASCII =  ((inputCharASCII + reverseInputCharASCII - (2 * 97) + 1) % 26) + 97;
                output = output + (char)outputCharASCII;
            }
            System.out.println(output);
        }
    }
}