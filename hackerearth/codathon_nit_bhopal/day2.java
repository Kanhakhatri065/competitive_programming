import java.util.Scanner;

public class day2{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();

        int matrix[][] = new int[n][n];

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                matrix[i][j] = scan.nextInt();
            }
        }

        int query = scan.nextInt();
        
        for(int i = 1;i<=query;i++){
            int type,a,b,c;
            type = scan.nextInt();
            a = scan.nextInt();
            b = scan.nextInt();
            c = scan.nextInt();

            if(type==1){
                for(int j = a-1;j < b;j++){
                    for(int k = 0;k < n;k++){
                        matrix[j][k] = matrix[j][k] ^ c;
                    }
                }
            }

            if(type == 2){
                for(int j = 0;j < n;j++){
                    for(int k = a-1;k < b;k++){
                        matrix[j][k] = matrix[j][k] ^ c;
                    }
                }
            }
        }

        int sum = 0;
        for(int i = 0;i < n;i++){
            sum = sum + matrix[i][i];
        }
       
        System.out.println(sum);
    }
}