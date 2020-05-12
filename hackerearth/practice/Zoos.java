import java.util.*;
class Zoos{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String word = scan.next();
        int z = 0;
        int o = 0;

        for(int i = 0;i < word.length();i++){
            if(word.charAt(i) == 'z'){
                z++;
            } else if(word.charAt(i) == 'o'){
                o++;
            }
        }

        if((z*2) == o){
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}