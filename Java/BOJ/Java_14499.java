import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

// class Dice {
//     int [] data = {0, 0, 0, 0, 0, 0};
//     int []  position

//     Dice(int top, int bottom) {
//         this.top = top;
//         this.bottom = bottom;
//     }
// }
public class Java_14499 {
    static int N, M, K;
    static int [][] board = null;
    static int [] dr = {1, -1, 0, 0};
    static int [] dc = {0, 0, -1, 1};
    static ArrayList<Integer> directions = new ArrayList<Integer>();
    // static int [] dice = {0, 0, 0, 0, 0, 0}; // 전개도

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] params = br.readLine().split(" ");
        String [] tokens = null;
        int sr = 0, sc = 0;

        N = Integer.parseInt(params[0]);
        M = Integer.parseInt(params[1]);
        sr = Integer.parseInt(params[2]);
        sc = Integer.parseInt(params[3]);
        K = Integer.parseInt(params[4]);

        board = new int[N][M];


        for (int r = 0; r < N; r++) {
            tokens = br.readLine().split(" ");
            for (int c = 0; c < M; c++) {
                board[r][c] = Integer.parseInt(tokens[c]);
            }
        }
        tokens =  br.readLine().split(" ");

        for (int k = 0; k < K; k++) {
            int dir = Integer.parseInt(tokens[k]);
            directions.add(dir - 1);
        }

        simulation(sr, sc);
    }

    public static void simulation(int sr, int sc) {
        // move and print
        int r = sr, c = sc;
        int [] dice = {0, 0, 0, 0, 0, 0};
        for (int k = 0; k < K; k++) {
            int dir = directions.get(k);

            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                if (board[nr][nc] == 0) {

                } else {

                }
            }
            // if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
            //     continue;
            // }

            // if (board[nr][nc] == 0)
        }
    }

    public static int [] getNextDice(int [] now, int direction) {
        int [] next = new int[N];
        for (int i = 0; i < 6; i++){
            next[i] = now[i];
        }
        switch(direction) {

            case 0: // 동
            next[0] = now[2];
            next[3] = now[0];
            next[2] = now[3];
            break;
            case 1: // 서
            next[3] = now[2];
            next[2] = now[0];
            next[0] = now[3];
            break;
            case 2: // 북
            next[1] = now[4];
            next[4] = now[0];
            next[0] = now[5];
            next[5] = now[1];
            break;
            case 3: // 남
            next[0] = now[4];
            next[5] = now[0];
            next[1] = now[5];
            next[4] = now[1];
            break;
        }
    }
    return next[];
}
