import java.util.*;

enum DIRECTION {
    E, S, W, N
};

public class CrossTheMaze {
    static String path = "";
    static int sx, sy, ex, ey;
    static int steps;
    static char[][] maze;
    static int n;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int testcases = scan.nextInt();
        for(int cases = 1;cases <= testcases;cases++) {
            n = scan.nextInt();
            maze = new char[n][n];
            for(int i = 0;i < n;i++) {
                maze[i] = scan.next().toCharArray();
            }

            sx = scan.nextInt();
            sy = scan.nextInt();
            ex = scan.nextInt();
            ey = scan.nextInt();
            sx--; sy--; ex--; ey--;

            int faceDirc = 0;
            if(sx == n - 1 && sy == 0) faceDirc = 1;
            if(sx == n - 1 && sy == n - 1) faceDirc = 2;
            if(sx == 0 && sy == n - 1) faceDirc = 3;

            path = "";
            steps = 0;

            if(findPath(faceDirc)) {
                System.out.println("Case #" + cases + ": " + steps);
                System.out.println(path);
            } else {
                System.out.println("Case #" + cases + ": " + "Edison ran out of energy.");
            }
        }
        
        scan.close();
    }

    private static boolean findPath(int faceDirc) {
        boolean found = false;
        while(steps <= 10000 && !found) {
            if(sx == ex && sy == ey) {
                found = true;
                break;
            }

            int startDirc = (faceDirc + 1) % 4;
            boolean findway = false;
            for(int i = 0;i < 4 && !findway;i++) {
                int num = (startDirc - i) % 4 >= 0 ? (startDirc - i) : (startDirc - i + 4);
                switch(num) {
                    case 0:
                        if(sx + 1 < n && maze[sx + 1][sy]== '.') {
                            findway = true;
                            steps++;
                            path = path + 'S';
                            faceDirc = 0;
                            sx++;
                        }
                    break;
                    case 1:
                        if(sy + 1 < n && maze[sx][sy + 1] == '.') {
                            findway = true;
                            steps++;
                            path = path + 'E';
                            faceDirc = 1;
                            sy++;
                        }
                    break;
                    case 2:
                        if(sx - 1 >= 0 && maze[sx - 1][sy] == '.') {
                            findway = true;
                            steps++;
                            path = path + 'N';
                            faceDirc = 2;
                            sx--;
                        }
                    break;
                    case 3:
                        if(sy - 1 >= 0 && maze[sx][sy - 1] == '.') {
                            findway = true;
                            steps++;
                            path = path + 'W';
                            faceDirc = 3;
                            sy--;
                        }
                    break;
                }
            }

            if(!findway) {
                steps = 20000;
            }
        }

        return found;
    }   
}