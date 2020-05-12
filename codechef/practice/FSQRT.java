import java.util.Scanner;

class FSQRT{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int testcases = scan.nextInt();

        for(int i = 1;i<=testcases;i++){
            int number = scan.nextInt();
            double numRoot = Math.sqrt(number);
            int answer = (int)numRoot;
            System.out.println(answer);
        }
    }
}