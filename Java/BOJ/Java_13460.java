import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Ball {
    int r, c, cnt;
    String color;
    Ball(int r, int c, String color, int cnt) {
        this.r = r;
        this.c = c;
        this.color = color;
        this.cnt = cnt;
    }
}
public class Java_13460 {
    static int dr [] = {-1, 0, 1, 0};
    static int dc [] = {0, 1, 0, -1};
    static int N, M, minCnt = Integer.MAX_VALUE;
    static String [][] board = null;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] params = br.readLine().split(" ");
        N = Integer.parseInt(params[0]);
        M = Integer.parseInt(params[1]);

       //  System.out.println("N = " + N + ", M = " + M);

        board = new String [N][M];

        Ball redBall = null, blueBall = null;
        for (int r = 0; r < N; r++) {
            String [] tokens = br.readLine().split("");
            // String tokens = br.readLine();
            for (int c = 0; c < M; c++) {
                board[r][c] = tokens[c];

                if ("R".equals(board[r][c]) == true) {
                    redBall = new Ball(r, c, "R", 1);
                } else if ("B".equals(board[r][c]) == true) {
                    blueBall = new Ball(r, c, "B", 1);
                }
            }
        }

        for (int dir = 0; dir < 4; dir++) {
        //    System.out.println("dir=" + dir);
            dfs(redBall, blueBall, dir);
        }

        if (minCnt == Integer.MAX_VALUE) {
            minCnt = -1;
        }
        System.out.println(minCnt);
    }
    public static void dfs(Ball red, Ball blue, int direction) {
        // System.out.println("red row = " + red.r + ", red col = " + red.c + ", red Cnt = " + red.cnt + ", Ball Color = " + red.color);
        // System.out.println("blue row = " + blue.r + ", blue col = " + blue.c + ", blue Cnt = " + blue.cnt + ", Ball Color = " + blue.color);
        // System.out.println("direction=" + direction);
        if (red.cnt > 10 || red.cnt > minCnt) {
            return ;
        }

        String start = "";
        // 1. 시작
        if (direction == 0) { // 북
            if (red.r < blue.r) {
                start = "R";
            } else {
                start = "B";
            }
        } else if (direction == 1) { // 동
            if (red.c > blue.c) {
                start = "R";
            } else {
                start = "B";
            }
        } else if (direction == 2) { // 남
            if (red.r > blue.r) {
                start = "R";
            } else {
                start = "B";
            }
        } else if (direction == 3) { // 서
            if (red.c < blue.c) {
                start = "R";
            } else {
                start = "B";
            }
        }

        // System.out.println("direction=" + direction + "start=" + start);
        Ball startBall = null;
        Ball endBall = null;
        Ball nextRed = null;
        Ball nextBlue = null;

        if ("R".equals(start) == true) {
            startBall = new Ball(red.r, red.c, red.color, red.cnt);
            endBall = new Ball(blue.r, blue.c, blue.color, blue.cnt);
        } else {
            startBall = new Ball(blue.r, blue.c, blue.color, blue.cnt);
            endBall = new Ball(red.r, red.c, red.color, red.cnt);
        }

        boolean outFlag = false;
        while(true) {
            int nr = startBall.r + dr[direction];
            int nc = startBall.c + dc[direction];
            if ("O".equals(board[nr][nc]) == true) {
                if ("R".equals(startBall.color) == true) {
                    startBall.r = nr;
                    startBall.c = nc;
                    outFlag = true;
                    break;
                } else { // 파랑
                    return ;
                }
            } else if ("#".equals(board[nr][nc]) == true) {
                if ("R".equals(startBall.color) == true) {
                    nextRed = startBall;
                    nextRed.cnt = startBall.cnt + 1;
                } else {
                    nextBlue = startBall;
                    nextBlue.cnt = startBall.cnt + 1;
                }
                break;
            } else {
                startBall.r = nr;
                startBall.c = nc;
            }
        }

        while(true) {
            int nr = endBall.r + dr[direction];
            int nc = endBall.c + dc[direction];
            if ("O".equals(board[nr][nc]) == true) {
                if ("R".equals(endBall.color) == true) {
                    if (minCnt > endBall.cnt) {
                        minCnt = endBall.cnt;
                    }
                }
                return ;
            } else if ("#".equals(board[nr][nc]) == true) {
                if ("R".equals(endBall.color) == true) {
                    nextRed = endBall;
                    nextRed.cnt = endBall.cnt + 1;
                } else {
                    nextBlue = endBall;
                    nextBlue.cnt = endBall.cnt + 1;
                }
                break;
            } else if (nr == startBall.r && nc == startBall.c) { // 겹치는 경우
                // endBall.r -= dr[direction];
                // endBall.c -= dc[direction];

                if ("R".equals(endBall.color) == true) {
                    nextRed = endBall;
                    nextRed.cnt = endBall.cnt + 1;
                } else {
                    nextBlue = endBall;
                    nextBlue.cnt = endBall.cnt + 1;
                }
                break;
            } else {
                endBall.r = nr;
                endBall.c = nc;
            }
        }

    //    System.out.println("startBall row = " + startBall.r + ", startBall col = " + startBall.c + ", startBall Cnt = " + startBall.cnt + ", startBall Color = " + startBall.color);
    //    System.out.println("endBall row = " + endBall.r + ", endBall col = " + endBall.c + ", endBall Cnt = " + endBall.cnt + ", Ball Color = " + endBall.color);

        if (outFlag == true) {
            if (minCnt > startBall.cnt) {
                minCnt = startBall.cnt;
            }
            return ;
        }

        for (int dir = 0; dir < 4; dir++) {
            dfs(nextRed, nextBlue, dir);
        }
    }
}
