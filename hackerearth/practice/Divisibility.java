import java.util.Scanner;

public class Divisibility{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int size = scan.nextInt();

        int []arr = new int[size];

        for(int i = 0;i < arr.length;i++){
            arr[i] = scan.nextInt();
        }

        int lastdigit = arr[arr.length - 1] % 10;

        if(lastdigit == 0){
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}