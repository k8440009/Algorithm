import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class Java_12100 {
    static int N, totalMaxBlock = 0;
    static int [][] board = null;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new int[N][N];
        for (int r = 0; r < N; r++) {
            String [] tokens = br.readLine().split(" ");
            for (int c = 0; c < N; c++){
                board[r][c] = Integer.parseInt(tokens[c]);
            }
        }
        
        for (int dir = 0; dir < 4; dir++) {
            dfs(board, dir, 1);
        }
        System.out.println(totalMaxBlock);
    }
    
    public static void dfs(int [][] basis, int direction, int cnt) {
        if (cnt > 5) {
            int maxBlock = 0;
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    if (basis[r][c] > maxBlock) {
                        maxBlock = basis[r][c];
                    }
                }
            }

            if (maxBlock > totalMaxBlock)
                totalMaxBlock = maxBlock;
            return ;
        }

        int [][] newBoard = new int[N][N];
        moveBlock(newBoard, basis, direction);

        for (int dir = 0; dir < 4; dir++) {
            dfs(newBoard, dir, cnt + 1);
        }

    }
    public static void moveBlock(int [][] newBoard, int [][] basis, int direction) {
        boolean [][] checkSum = new boolean[N][N];
        if (direction == 0) { // 북
            for (int c = 0; c < N; c++) {
                int r = 0;
                int saveR = 0;
                while (true) {
                    
                    if (r >= N) {
                        break;
                    }
                    if (basis[r][c] != 0) {
                        if (r == 0) {
                            saveR = 0;
                            newBoard[saveR][c] = basis[r][c];
                        } else {
                            if (basis[r][c] == newBoard[saveR][c]) { // 같은 경우
                                if (checkSum[saveR][c] == false) { // 합쳐칠 수 있는 경우
                                    checkSum[saveR][c] = true;
                                    newBoard[saveR][c] += basis[r][c];
                                } else {
                                    saveR += 1;
                                    newBoard[saveR][c] = basis[r][c];
                                }
                            } else {  // 아닌 경우
                                saveR += 1;
                                newBoard[saveR][c] = basis[r][c];
                            }
                        }
                    }
                    r += 1;
                }
            }
        } else if (direction == 1) { // 동
            for (int r = 0; r < N; r++) {
                int c = N - 1;
                int saveC = N - 1;

                while(true) {
                    if (c < 0) {
                        break;
                    }

                    if (basis[r][c] != 0) {
                        if (c == N - 1) {
                            saveC = N - 1;
                            newBoard[r][saveC] = basis[r][c];
                        } else {
                            if (basis[r][c] == newBoard[r][saveC]) { // 같은 경우
                                if (checkSum[r][c] == false) { // 합쳐칠 수 있는 경우
                                    checkSum[r][c] = true;
                                    newBoard[r][saveC] += basis[r][c];
                                } else {
                                    saveC -= 1;
                                    newBoard[r][saveC] = basis[r][c];
                                }
                            } else {  // 아닌 경우
                                saveC -= 1;
                                newBoard[r][c] = basis[r][saveC];
                            }
                        }
                    }
                    c -= 1;
                }
            }
        } else if (direction == 2) { // 남
            for (int c = 0; c < N; c++) {
                int r = N - 1;
                int saveR = N - 1;
                while (true) {
                    if (r < 0) {
                        break;
                    }

                    if (basis[r][c] != 0) {
                        if (r == N - 1) {
                            saveR = N - 1;
                            newBoard[saveR][c] = basis[r][c];
                        } else {
                            if (basis[r][c] == newBoard[saveR][c]) { // 같은 경우
                                if (checkSum[saveR][c] == false) { // 합쳐칠 수 있는 경우
                                    checkSum[saveR][c] = true;
                                    newBoard[saveR][c] += basis[r][c];
                                } else {
                                    saveR -= 1;
                                    newBoard[saveR][c] = basis[r][c];
                                }
                            } else {  // 아닌 경우
                                saveR -= 1;
                                newBoard[saveR][c] = basis[r][c];
                            }
                        }
                    }
                    r -= 1;
                }
            }
        } else { // 서
            for (int r = 0; r < N; r++) {
                int c = 0;
                int saveC = 0;

                while(true) {
                    if (c >= N) {
                        break;
                    }

                    if (basis[r][c] != 0) {
                        if (c == 0) {
                            saveC = 0;
                            newBoard[r][saveC] = basis[r][c];
                        } else {
                            if (basis[r][c] == newBoard[r][saveC]) { // 같은 경우
                                if (checkSum[r][c] == false) { // 합쳐칠 수 있는 경우
                                    checkSum[r][c] = true;
                                    newBoard[r][saveC] += basis[r][c];
                                } else {
                                    saveC += 1;
                                    newBoard[r][saveC] = basis[r][c];
                                }
                            } else {  // 아닌 경우
                                saveC += 1;
                                newBoard[r][c] = basis[r][saveC];
                            }
                        }
                    }
                    c += 1;
                }
            }
        }
        // System.out.println("direction=" + direction);
        // printBoard(newBoard);
    }
    // public static void boardCopy (int [][] copy, int [][] src) {
    //     for (int r = 0; r < N; r++) {
    //         for (int c = 0; c < N; c++) {
    //             copy[r][c] = src[r][c];
    //         }
    //     }
    // }
    public static void printBoard(int [][] src) {
        System.out.println();
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                System.out.print(src[r][c]);
                System.err.print(" ");
            }
            System.out.println();
        }
    }
}
