import java.util.*;

class SplitHouses{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int grid = scan.nextInt();
        String village = scan.next();

        if(village.contains("HH")){
            System.out.println("NO");
        } else {
            village = village.replace(".", "B");
            System.out.println("YES");
            System.out.println(village);
        }
    }
}