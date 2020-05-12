import java.util.*;

public class CityTravel{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int total = scan.nextInt();
        int regular = scan.nextInt();
        int exceptions = scan.nextInt();

        HashMap<Integer,Integer> exception = new HashMap<>(exceptions);

        for(int i = 0;i < exceptions;i++){
            int key = scan.nextInt();
            int value = scan.nextInt();
            exception.put(key, value);
        }

        int days = 1;
        while(total != 0){
            int that_day_travel = 0;
            if(exception.get(days) != null){
                that_day_travel = exception.get(days);
            } else {
                that_day_travel = regular;
            }
            if(total <= that_day_travel){
                total = 0;
                break;
            }
            total -= that_day_travel;
            days++;
        }

        System.out.println(days);
    }
}