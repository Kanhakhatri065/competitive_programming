import java.util.Scanner;

public class TwoStrings{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        int testcases = scan.nextInt();
        for(int i = 0;i < testcases;i++){
            String firstStr = scan.next();
            String secondStr = scan.next();

            int length = firstStr.length();
            for(int j = 0;j < firstStr.length();j++){
                for(int k = 0;k < secondStr.length();k++){
                    if(firstStr.charAt(j) == secondStr.charAt(k)){
                        length--;
                        secondStr = secondStr.substring(0, k) + "$" + secondStr.substring(k+1, secondStr.length());
                        break;
                    }
                }
            }

            if(length == 0){
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}