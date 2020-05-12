import java.util.*;

public class Anagrams{

    static String swap(String str, int i, int j) 
    { 
        if (j == str.length() - 1) 
            return str.substring(0, i) + str.charAt(j) 
                + str.substring(i + 1, j) + str.charAt(i); 
  
        return str.substring(0, i) + str.charAt(j) 
            + str.substring(i + 1, j) + str.charAt(i) 
            + str.substring(j + 1, str.length()); 
    } 

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int testcases = scan.nextInt();

        while(testcases != 0){
            testcases--;
            String firstStr = scan.next();
            String secondStr = scan.next();

            int firstLength = firstStr.length();
            int secondLength = secondStr.length();

            int count = 0;
            for(int i = 0;i < firstLength;i++){
                for(int j = 0;j < secondLength;j++){
                    if(firstStr.charAt(i) == secondStr.charAt(j)){
                        for(int k=i;k< firstLength - 1;k++){
                            firstStr = swap(firstStr,k,k+1);
                        } 
                        firstLength--;
                        for(int k=j;k<secondLength - 1;k++){
                            secondStr = swap(secondStr,k,k+1);
                        } 
                        secondLength--;
                        i--;
                    }
                }
            }

            int deletions = firstLength + secondLength;

            System.out.println(deletions);
        }
    }
}