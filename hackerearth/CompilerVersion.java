import java.io.*;
import java.util.*;

public class CompilerVersion {
    public static void main(String[] args) {
        String name = "";

        Scanner scan = new Scanner(System.in);

        while(scan.hasNextLine()) {
            name = scan.nextLine();
            int k = name.indexOf("//");
            if(k != -1) {
                String s_new = name.substring(0, k);
                System.out.println(s_new.replaceAll("->", ".") + name.substring(k));
            } else {
                System.out.println(name.replaceAll("->", "."));
                continue;
            }
        }
    }
}