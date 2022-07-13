import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Cleaner {
    int r, c, dir;
    Cleaner(int r, int c, int dir) {
        this.r = r;
        this.c = c;
        this.dir = dir;
    }
}

public class Java_14503 {
    static int [] dr = {-1, 0, 1, 0};
    static int [] dc = {0, 1, 0, -1};
    static int N, M;
    static int [][] board = null;
    static boolean [][] visited = null;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] params = br.readLine().split(" ");
        N = Integer.parseInt(params[0]);
        M = Integer.parseInt(params[1]);
        board = new int [N][M];
        visited = new boolean[N][M];
        params = br.readLine().split(" ");

        int tmpR = Integer.parseInt(params[0]);
        int tmpC = Integer.parseInt(params[1]);
        int tmpDir = Integer.parseInt(params[2]);
        Cleaner cleaner = new Cleaner(tmpR, tmpC, tmpDir);
        for (int i = 0; i < N; i++) {
            String [] tokens = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(tokens[j]);
            }
        }

        while(true) {
            boolean stop = false;
            int nowR = cleaner.r;
            int nowC = cleaner.c;
            int nowDir = cleaner.dir;
            visited[nowR][nowC] = true;

            for (int cnt = 0; cnt < 4; cnt++) {
                int nd = (nowDir - 1 + 4) % 4; // 왼쪽 방향
                int nr = nowR + dr[nd];
                int nc = nowC + dc[nd];
                // 2 - 1
                if (board[nr][nc] == 0 && visited[nr][nc] == false) {
                    cleaner.r = nr;
                    cleaner.c = nc;
                    cleaner.dir = nd;
                    break;
                }
                // 4방향 모두 회전
                if (cnt == 3) {
                    int backDir = (nd + 2) % 4;
                    int backR = nowR + dr[backDir];
                    int backC = nowC + dc[backDir];

                    if (board[backR][backC] == 1) {
                        stop = true;
                    } else {
                        cleaner.r = backR;
                        cleaner.c = backC;
                        cleaner.dir = nd;
                    }
                } else {
                    nowDir = nd;
                }
            }

            if (stop == true) {
                break;
            }
        }
        int cnt = 0;
        int blank = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 0 && visited[i][j] == true) {
                    cnt +=1;
                }
            }
        }
        System.out.println(cnt);
    }
}