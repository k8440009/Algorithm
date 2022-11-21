import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Java_10026 {
    static int N, area1 = 0, area2 = 0;
    static String [][] board = null;
    static boolean [][] visited = null;
    static int [] dr = {1, 0, -1, 0};
    static int [] dc = {0, 1, 0 ,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        board = new String[N][N];
        for (int i = 0; i < N; i++) {
            String [] tokens = br.readLine().split("");
            board[i] = Arrays.copyOf(tokens, N);
        }

        visited = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j  < N; j++){
                if (visited[i][j] == false) {
                    area1 += 1;

                    dfs1(i, j, board[i][j]);
                }
            }
        }
        visited = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j  < N; j++){
                if (visited[i][j] == false) {
                    area2 += 1;

                    dfs2(i, j, board[i][j]);
                }
            }
        }
        System.out.println(area1 + " " + area2);
    }
    public static void dfs1(int r, int c, String color) {
        visited[r][c] = true;

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] == true) {
                continue;
            }
            if (color.equals(board[nr][nc]) == false) {
                continue;
            }
            dfs1(nr, nc, color);
        }
    }

    public static void dfs2(int r, int c, String color) {
        visited[r][c] = true;

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] == true) {
                continue;
            }
            // 적록 색약
            if (color.equals("R") == true || color.equals("G") == true) {
                if (board[nr][nc].equals("R") == true || board[nr][nc].equals("G") == true)
                    dfs2(nr, nc, color);
            } else {
                if (color.equals(board[nr][nc]) == true) {
                    dfs2(nr, nc, color);
                }
            }
        }
    }
}