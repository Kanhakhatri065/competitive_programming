import java.util.Scanner;

public class DedicationLevel{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int size = scan.nextInt();

        String []names = new String[size];
        int []hours = new int[size];

        for(int i = 0;i < size;i++){
            names[i] = scan.next();
            hours[i] = scan.nextInt();
        }
        
        int intTemp = 0;
        String strTemp = "";
        for(int i = 0;i < size;i++){
            for(int j = 0;j < size - i - 1;j++){
                if(hours[j] > hours[j+1]){
                    intTemp = hours[j];
                    hours[j] = hours[j + 1];
                    hours[j + 1] = intTemp;
                    
                }
            }
        }
    }
}