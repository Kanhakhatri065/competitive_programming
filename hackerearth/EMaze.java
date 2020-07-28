import java.util.Scanner;

public class EMaze{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String directions = scan.next();

        int x = 0;
        int y = 0;

        for(int i = 0;i < directions.length();i++){
            char dir = directions.charAt(i);

            if(dir == 'L'){
                x--;
            } else if(dir == 'R'){
                x++;
            } else if(dir == 'U'){
                y++;
            } else if(dir == 'D'){
                y--;
            }
        }
        System.out.println(x + " " + y);
    }
}