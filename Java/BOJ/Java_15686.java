import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Location {
    int r, c;
    Location (int r, int c) {
        this.r = r;
        this.c = c;
    }
}

public class Java_15686 {
    static int N, M, totalMinLength = Integer.MAX_VALUE;
    static int [][] board = null;
    static ArrayList <Location> homeArr = new ArrayList<Location>();
    static ArrayList <Location> chickenArr = new ArrayList<Location>();
    static boolean [] checked = null;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] params = br.readLine().split(" ");
        N = Integer.parseInt(params[0]);
        M = Integer.parseInt(params[1]);

        board = new int [N][N];
        for (int r = 0; r < N; r++) {
            String [] tokens = br.readLine().split(" ");
            for (int c = 0; c < N; c++) {
                board[r][c] = Integer.parseInt(tokens[c]);

                if (board[r][c] == 1) {
                    homeArr.add(new Location(r, c));
                } else if (board[r][c] == 2) {
                    chickenArr.add(new Location(r, c));
                }
            }
        }
        
        checked = new boolean[chickenArr.size()];

        dfs(0, 0);

        System.out.println(totalMinLength);

    }

    public static void dfs(int index, int cnt) {
        if (cnt == M) {
            ArrayList <Location> chickens = new ArrayList<Location>();
            for (int i = 0; i < chickenArr.size(); i++) {
                if (checked[i] == true) {
                    chickens.add(new Location(chickenArr.get(i).r, chickenArr.get(i).c));
                }
            }

            int chickenLenth = 0;
            for (int i = 0; i < homeArr.size(); i++) {
                int minLength = Integer.MAX_VALUE;
                int hr = homeArr.get(i).r;
                int hc = homeArr.get(i).c;

                for (int j = 0; j < chickens.size(); j++) {
                    int cr = chickens.get(j).r;
                    int cc = chickens.get(j).c;
                    
                    int sum = Math.abs(hr - cr) + Math.abs(hc - cc);
                    if (minLength > sum) {
                        minLength = sum;
                    }
                }

                chickenLenth += minLength;
            }

            if (totalMinLength > chickenLenth) {
                totalMinLength = chickenLenth;
            }

            return ;
        }

        for (int i = index; i < chickenArr.size(); i++) {
            if (checked[i] == true)
                continue;

            checked[i] = true;
            dfs(i, cnt + 1);
            checked[i] = false;
        }
    }
}
