import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

class Virus {
    int r, c;
    Virus(int r, int c) {
        this.r = r;
        this.c = c;
    }
}

public class Java_14502 {
    static int N, M;
    static int [] dr = {-1, 0, 1, 0};
    static int [] dc = {0, 1, 0, -1};
    static int [][] board = null;
    static int maxCnt = 0;
    static ArrayList <Virus> virusArr = new ArrayList<Virus>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String [] param = br.readLine().split(" ");
        N = Integer.parseInt(param[0]);
        M = Integer.parseInt(param[1]);

        board = new int [N][M];

        for (int r = 0; r < N; r++) {
            String [] tokens = br.readLine().split(" ");
            for (int c = 0; c < M; c++) {
                board[r][c] = Integer.parseInt(tokens[c]);
                if (board[r][c] == 2) {
                    virusArr.add(new Virus(r, c));
                }
            }
        }

        dfs(0, 0, 0);

        System.out.println(maxCnt);
    }

    public static void dfs(int sr, int sc, int cnt) {
        if (cnt > 3) {
            return ;
        } else {
            if (cnt == 3) {
                int [][] newBoard = new int [N][M];
                for (int r = 0; r < N; r++) {
                    for (int c = 0; c < M; c++) {
                        newBoard[r][c] = board[r][c];
                    }
                }

                bfs(newBoard);
            }
        }

        int startC = sc;

        for (int r = sr; r < N; r++) {
            for (int c = startC; c < M; c++) {
                if (board[r][c] == 0) {
                    board[r][c] = 1;
                    dfs(r, c, cnt + 1);
                    board[r][c] = 0;
                }
            }
            startC = 0;
        }
    }

    public static void bfs(int [][] newBoard) {
        Queue <Virus> que = new LinkedList<Virus>();
        boolean [][] visited = new boolean [N][M];
        for (Virus virus : virusArr) {
            que.add(new Virus(virus.r, virus.c));
            visited[virus.r][virus.c] = true;
        }

        while(!que.isEmpty()) {
            Virus now = que.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nr = now.r + dr[dir];
                int nc = now.c + dc[dir];

                if (nr < 0 || nr >= N || nc < 0 || nc >=M || visited[nr][nc]) {
                    continue;
                }

                if (newBoard[nr][nc] == 0) {
                    newBoard[nr][nc] = 2;
                    visited[nr][nc] = true;

                    que.add(new Virus(nr, nc));
                }
            }
        }

        int cnt = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c  < M; c++) {
                if (newBoard[r][c] == 0) {
                    cnt += 1;
                }
            }
        }

        if (cnt > maxCnt) {
            maxCnt = cnt;
        }
    }
}
