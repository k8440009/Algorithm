import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_12100 {
    static int N;
    static int [][] board = null;
    static int [] dr = {-1, 0, 1, 0};
    static int [] dc = {0, 1, 0, -1};
    static int maxCnt = 0;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        board = new int[N][N];

        for (int r = 0; r < N; r++) {
            String [] tokens = br.readLine().split(" ");
            for (int c = 0; c < N; c++) {
                board[r][c] = Integer.parseInt(tokens[c]);
            }
        }

        for (int dir = 0; dir < 4; dir++) {
            dfs (board, dir, 1);
        }

        System.out.println(maxCnt);
    }

    public static void dfs(int [][] now, int direction, int cnt) {
        if (cnt > 5) {
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    if (now[r][c] > maxCnt) {
                        maxCnt = now[r][c];
                    }
                }
            }
            return ;
        }

        int [][] next = new int[N][N];
        moveBlock(next, now, direction);

        // printBoard(next, cnt, direction);

        for (int dir = 0; dir < 4; dir++) {
            dfs(next, dir, cnt + 1);
        }
    }

    public static void moveBlock(int [][] next, int [][] now, int direction) {
        if (direction == 0) { // 북
            for (int c = 0; c < N; c++) {
                int r = 0; // now
                int nr = 0; // next
                boolean sum = false;
                while(true) {
                    if (now[r][c] != 0) {
                        if (now[r][c] == next[nr][c]) {
                            if (sum == false) {
                                next[nr][c] += now[r][c];
                                sum = true;
                            } else {
                                nr += 1;
                                next[nr][c] = now[r][c];
                                sum = false;
                            }
                        } else {
                            if (next[nr][c] != 0) {
                                nr +=1;
                            }
                            next[nr][c] = now[r][c];
                            sum = false;
                        }
                    }
                    r += 1;
                    if (r >= N)
                        break;
                }
            }
        } else if (direction == 1) { // 동
            for (int r = 0; r < N; r++) {
                int c = N - 1;
                int nc = N - 1;
                boolean sum = false;

                while(true) {
                    if (now[r][c] != 0) {
                        if (now[r][c] == next[r][nc]) {
                            if (sum == false) {
                                next[r][nc] += now[r][c];
                                sum = true;
                            } else {
                                nc -= 1;
                                next[r][nc] = now[r][c];
                                sum = false;
                            }
                        } else {
                            if (next[r][nc] != 0) {
                                nc -= 1;
                            }
                            next[r][nc] = now[r][c];
                            sum = false;
                        }
                    }
                    c -= 1;
                    if (c < 0)
                        break;
                }
            }
        } else if (direction == 2) { // 남
            for (int c = 0; c < N; c++) {
                int r = N - 1; // now
                int nr = N - 1; // next
                boolean sum = false;
                while(true) {
                    if (now[r][c] != 0) {
                        if (now[r][c] == next[nr][c]) {
                            if (sum == false) {
                                next[nr][c] += now[r][c];
                                sum = true;
                            } else {
                                nr -= 1;
                                next[nr][c] = now[r][c];
                                sum = false;
                            }
                        } else {
                            if (next[nr][c] != 0) {
                                nr -=1;
                            }
                            next[nr][c] = now[r][c];
                            sum = false;
                        }
                    }
                    r -= 1;
                    if (r < 0)
                        break;
                }
            }
        } else if (direction == 3) { // 서
            for (int r = 0; r < N; r++) {
                int c = 0;
                int nc = 0;
                boolean sum = false;

                while(true) {
                    if (now[r][c] != 0) {
                        if (now[r][c] == next[r][nc]) {
                            if (sum == false) {
                                next[r][nc] += now[r][c];
                                sum = true;
                            } else {
                                nc += 1;
                                next[r][nc] = now[r][c];
                                sum = false;
                            }
                        } else {
                            if (next[r][nc] != 0) {
                                nc += 1;
                            }
                            next[r][nc] = now[r][c];
                            sum = false;
                        }
                    }
                    c += 1;
                    if (c >= N)
                        break;
                }
            }
        }
    }

    static void printBoard(int [][] tmp, int cnt, int direction) {
        System.out.println();
        System.out.println("cnt=" + cnt + "direction="  + direction);
        for (int r = 0; r < N; r++) {
            for (int c = 0; c  < N; c++) {
                System.out.print(tmp[r][c]  + " ");
            }
            System.out.println();
        }
    }
}
