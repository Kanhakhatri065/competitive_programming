import java.util.Scanner;

public class Cipher{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String text = scan.next();
        int key = scan.nextInt();

        String output = "";
        for(int i = 0;i < text.length();i++){
            char c = text.charAt(i);
            int ch = c;
            if(ch >= 65 && ch <= 90){
                ch += key;
                if(ch > 90){
                    ch =  (65 + (ch - 90));
                }
            } else if(ch >= 97 && ch <= 112){
                ch  += key;
                if(ch >122){
                    ch =  97 + (ch - 123);
                }
            } else if(ch >= 48 && ch <= 57){
                ch += key;
                if(ch > 57){
                    ch = (48 + (ch - 58));
                }
            }

            c = (char) ch;
            output += c;
        }

        System.out.println(output);
    }
}