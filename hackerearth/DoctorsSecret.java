import java.util.Scanner;


public class DoctorsSecret{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int length = scan.nextInt();
        int pages = scan.nextInt();

        if((length <= 23) && ((pages >= 500) && (pages <= 1000))){
            System.out.println("Take Medicine");
        } else {
            System.out.println("Don't take Medicine");
        }
    }
}