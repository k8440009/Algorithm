import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_1743 {
    static int [] dr = {-1, 0, 1, 0};
    static int [] dc = {0, 1, 0, -1};
    static int N, M, K;
    static int board[][] = null;
    static boolean visited[][] = null;
    static int maxCnt = -1;
    static int foodCnt = 1;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] tokens = br.readLine().split(" ");
        String [] pos = null;
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        K = Integer.parseInt(tokens[2]);

        board = new int [N][M];
        visited = new boolean [N][M];

        for (int k = 0; k < K; k++){
            pos = br.readLine().split(" ");
            board[Integer.parseInt(pos[0]) - 1][Integer.parseInt(pos[1]) - 1] = 1;
        }

        for (int r = 0; r < N; r++){
            for (int c = 0; c < M; c++){
                if (board[r][c] == 1 
                    && visited[r][c] == false){
                    foodCnt = 0;
                    dfs(r, c);

                    if (foodCnt > maxCnt)
                        maxCnt = foodCnt;
                }
            }
        }

        System.out.println(maxCnt);
    }

    public static void dfs(int r, int c){
        int nr = -1, nc = -1;
        visited[r][c] = true;
        foodCnt += 1;
        for (int dir = 0; dir < 4; dir++){
            nr = r + dr[dir];
            nc = c + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;
            if (board[nr][nc] != 1 || visited[nr][nc] == true)
                continue;
            dfs(nr, nc);
        }
    }
}
