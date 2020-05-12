import java.util.Scanner;


public class VowelRecognition{

    static boolean isVowel(char ch) 
    { 
        ch = Character.toUpperCase(ch); 
        return (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'); 
    } 

    static int countVowels(String str) 
    { 
        int count = 0; 
        for (int i = 0; i < str.length(); i++) 
            if (isVowel(str.charAt(i))) // Check for vowel 
                ++count; 
        return count; 
    } 

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int testcases = scan.nextInt();

        for(int i = 0;i < testcases;i++){
            String str = scan.next();

            int sum = 0;
            for(int j = 0;j < str.length();j++){
                for(int k = str.length();k > j;k--){
                    String tempStr = str.substring(j, k);
                    sum += countVowels(tempStr);
                }
            }

            System.out.println(sum);
        }
    }
}