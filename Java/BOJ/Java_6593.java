import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_6593 {
    static int L, R, C;
    static String [][][] board = null;
    static int dr [] = {};
    static int dc [] = {};
    static int dl [] = {};
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


        while(true) {
            String [] params = br.readLine().split(" ");
            
            L = Integer.parseInt(params[0]);
            R = Integer.parseInt(params[1]);
            C = Integer.parseInt(params[2]);

            if (L == 0 && R == 0 && C == 0) {
                break;
            }

            board = new String[L][R][C];
            for (int l = 0; l < L; l++){
                for (int r = 0; r < R; r++){
                    String [] tokens = br.readLine().split("");
                    for (int c = 0; c < C; c++){
                        board[l][r][c] = tokens[c];
                    }
                }
            }

            bfs();
        }
    }

    public static void bfs() {

    }
}
