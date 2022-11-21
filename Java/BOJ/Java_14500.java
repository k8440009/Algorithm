import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_14500 {
    static int N, M;
    static int [][] board = null;
    // size r, c
    static String [][] tetromino = {
        // 1
        {
        "1111",
        "0000",
        "0000",
        "0000"
        },
        {
        "1000",
        "1000",
        "1000",
        "1000"
        },
        // 2
        {
        "1100",
        "1100",
        "0000",
        "0000"
        },
        // 3
        {
        "1000",
        "1000",
        "1100",
        "0000"
        },
        {
        "0100",
        "0100",
        "1100",
        "0000"
        },
        {
        "1100",
        "1000",
        "1000",
        "0000"
        },
        {
        "1100",
        "0100",
        "0100",
        "0000"
        },
        {
        "1110",
        "1000",
        "0000",
        "0000"
        },
        {
        "1110",
        "0010",
        "0000",
        "0000"
        },
        {
        "1000",
        "1110",
        "0000",
        "0000"
        },
        {
        "0010",
        "1110",
        "0000",
        "0000"
        },
        // 4
        {
        "1000",
        "1100",
        "0100",
        "0000"
        },
        {
        "0100",
        "1100",
        "1000",
        "0000"
        },
        {
        "0110",
        "1100",
        "0000",
        "0000"
        },
        {
        "1100",
        "0110",
        "0000",
        "0000"
        },
        // 5
        {
        "0100",
        "1110",
        "0000",
        "0000"
        },
        {
        "1000",
        "1100",
        "1000",
        "0000"
        },
        {
        "1110",
        "0100",
        "0000",
        "0000"
        },
        {
        "0100",
        "1100",
        "0100",
        "0000"
        },
    };
    // 4 * 4
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] params = br.readLine().split(" ");
        int maxCnt = 0;
        N = Integer.parseInt(params[0]);
        M = Integer.parseInt(params[1]);

        board = new int[N + 4][M + 4];

        for (int r = 0; r < N; r++) {
            String [] tokens = br.readLine().split(" ");
            for (int c = 0; c < M; c++) {
                board[r][c] = Integer.parseInt(tokens[c]);
            }
        }
        for (int sr = 0; sr < N; sr++) {
            for (int sc = 0; sc < M; sc++) {
                // 테트로미노 놓기
                for (int size = 0; size < tetromino.length; size++) {
                    int cnt = 0;
                    boolean flag = false;
                    for (int r = 0; r < 4; r++) {
                        for (int c = 0; c < 4; c++) {
                            String data = Character.toString(tetromino[size][r].charAt(c));

                            if (sr + r >= N || sc + c >= M) {
                                if (data.equals("1")) {
                                    flag = true;
                                }
                            } else {
                                if (data.equals("1")) {
                                    cnt += board[sr + r][sc + c];
                                }
                            }
                        }
                    }

                    if (flag == false && cnt > maxCnt) {
                        maxCnt = cnt;
                        // System.out.println("sr=" + sr + " sc=" + sc + " size=" + size + " cnt=" + maxCnt);
                    }
                }
            }
        }

        System.out.println(maxCnt);
    }
}
