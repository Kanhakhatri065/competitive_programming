import java.util.Scanner;

public class AMovement{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int position = scan.nextInt();

        int steps = position / 5;
        int lastStep = position % 5;

        if(lastStep != 0){
            System.out.println(steps + lastStep);
        } else {
            System.out.println(steps);
        }
    }
}