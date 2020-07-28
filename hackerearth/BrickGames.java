import java.util.Scanner;

public class BrickGames{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int total_bricks = scan.nextInt();
        int temp = total_bricks;
        
        for(int i = 1;i < total_bricks;i++){
            if(i < temp){
                temp = temp -i;
            } else{
                temp = 0;
                System.out.println("Patlu");
                break;
            }

            if((i * 2) < temp){
                temp = temp - (i * 2);
            } else {
                temp = 0;
                System.out.println("Motu");
                break;
            }
        }
    }
}