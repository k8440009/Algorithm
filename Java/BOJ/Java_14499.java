import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Java_14499 {
    static int N, M, K;
    static int [][] board = null;
    static int [] dr = {0, 0, -1, 1};
    static int [] dc = {1, -1, 0, 0};
    static ArrayList<Integer> directions = new ArrayList<Integer>();

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] params = br.readLine().split(" ");
        String [] tokens = null;
        int sr = 0;
        int sc = 0;

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
        int [] dice = {0, 0, 0, 0, 0, 0};
        int r = sr;
        int c = sc;
        for (int k = 0; k < K; k++) {
            int dir = directions.get(k);

            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                dice = getNextDice(dice, dir);
                if (board[nr][nc] == 0) {
                    board[nr][nc] = dice[5];
                } else {
                    dice[5] = board[nr][nc];
                    board[nr][nc] = 0;
                }

                r = nr;
                c = nc;

                System.out.println(dice[0]);
            }
        }
    }

    public static int [] getNextDice(int [] now, int direction) {
        int [] next = new int[6];

        for (int i = 0; i < 6; i++){
            next[i] = now[i];
        }
        
        switch(direction) {
            case 0: // 동
            next[3] = now[5];
            next[0] = now[3];
            next[2] = now[0];
            next[5] = now[2];
            break;
            case 1: // 서
            next[2] = now[5];
            next[5] = now[3];
            next[3] = now[0];
            next[0] = now[2];
            break;
            case 2: // 북
            next[5] = now[1];
            next[1] = now[0];
            next[0] = now[4];
            next[4] = now[5];
            break;
            case 3: // 남
            next[0] = now[1];
            next[4] = now[0];
            next[5] = now[4];
            next[1] = now[5];
            break;
        }
        return next;
    }
}
