import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_14890 {
    static int N, L;
    static int [][] board = null;
    static int [][] rotBoard = null;
    static boolean [][] visited = null;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] params = br.readLine().split(" ");
        N = Integer.parseInt(params[0]);
        L = Integer.parseInt(params[1]);

        board = new int [N][N];
        rotBoard = new int [N][N];
        visited = new boolean[N][N];

        for (int r = 0; r < N; r++) {
            String [] tokens = br.readLine().split(" ");
            for (int c = 0; c < N; c++) {
                board[r][c] = Integer.parseInt(tokens[c]);
            }
        }

        rotateBoard(board, rotBoard);
        // 가로, 세로
        // 가로
        int totalCnt = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N-1; c++) {
                int now = board[r][c];
                int next = board[r][c + 1];

                if (Math.abs(now - next) == 1) {
                    // 이전 L개 체크
                    if (checkRoadRow(r, c, now, next, board) == false){
                        break;
                    }
                } else if (Math.abs(now - next) > 1) {
                    break;
                }

                if (c + 2 == N) {
                    totalCnt += 1;
                }
            }
        }

        visited = new boolean[N][N];
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N-1; c++) {
                int now = rotBoard[r][c];
                int next = rotBoard[r][c + 1];

                if (Math.abs(now - next) == 1) {
                    // 이전 L개 체크
                    if (checkRoadRow(r, c, now, next, rotBoard) == false){
                        break;
                    }
                } else if (Math.abs(now - next) > 1) {
                    break;
                }

                if (c + 2 == N) {
                    totalCnt += 1;
                }
            }
        }

        System.out.println(totalCnt);
    }

    public static boolean checkRoadRow(int sr, int sc, int now, int next, int [][] bassBoard) {
        if (now < next) { // 다음이 큰 경우 (now < next)
             // 경사로를 놓을 수 없는 경우
            if (sc - L + 1 < 0) {
                return false;
            }
            for (int c = sc; c >= sc - L + 1; c--) {
                // 평평하지 않거나, 이전에 다리를 놓은 경우
                if (bassBoard[sr][c] != now || visited[sr][c] == true) {
                    return false;
                }
            }

            for (int c = sc; c >= sc - L + 1; c--) {
                // 다리 놓기
                visited[sr][c] = true;
            }
        } else { // 이전이 큰 경우 (now > next)
            if (sc + L >= N) {
                return false;
            }

            for (int c = sc + 1; c <= sc + L; c++) {
                if (bassBoard[sr][c] != next || visited[sr][c] == true) {
                    return false;
                }
            }
            for (int c = sc + 1; c <= sc + L; c++) {
                visited[sr][c] = true;
            }
        }
        return true;
    }

    public static void rotateBoard(int [][] src, int [][] copy) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                copy[r][c] = src[N - c - 1][r];
            }
        }
    }
}
