import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_14891 {
    static int [][] block = new int[4][8];
    static int K;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] tokens = null;
        for (int i = 0; i < 4; i++) {
            tokens = br.readLine().split("");
            for (int j = 0; j < 8; j++) {
                block[i][j] = Integer.parseInt(tokens[j]);
            }
        }
        K = Integer.parseInt(br.readLine());

        for (int k = 0; k < K; k++) {
            int [] chkRotate = new int[4];
            tokens = br.readLine().split(" ");
            int blockNum = Integer.parseInt(tokens[0]) - 1;
            int rotateDir = Integer.parseInt(tokens[1]);

            chkRotate(chkRotate, blockNum, rotateDir);
            for (int i = 0; i < 4; i++) {
                if (chkRotate[i] != 0) {
                    rotate(i, chkRotate[i]);
                }
            }
           // printBlock(k, chkRotate);
        }

        int score = 0;
        if (block[0][0] == 1) {
            score += 1;
        }
        if (block[1][0] == 1) {
            score += 2;
        }
        if (block[2][0] == 1) {
            score += 4;
        }
        if (block[3][0] == 1) {
            score += 8;
        }
        System.out.println(score);
    }
    public static void chkRotate(int [] chkRotate, int num, int dir) {
        chkRotate[num] = dir;
        int nextDir = dir;
        if (num == 0) {
            if (block[0][2] != block[1][6]) {
                nextDir *= -1;
                chkRotate[1] = nextDir;

                if (block[1][2] != block[2][6]) {
                    nextDir *= -1;
                    chkRotate[2] = nextDir;

                    if (block[2][2] != block[3][6]) {
                        nextDir *= -1;
                        chkRotate[3] = nextDir;
                    }
                }
            }
        } else if (num == 1) {
            if (block[1][6] != block[0][2]) {
                nextDir *= -1;
                chkRotate[0] = nextDir;
            }

            nextDir = dir;
            if (block[1][2] != block[2][6]) {
                nextDir *= -1;
                chkRotate[2] = nextDir;
                if (block[2][2] != block[3][6]) {
                    nextDir *= -1;
                    chkRotate[3]= nextDir;
                }
            }
        } else if (num == 2) {
            if (block[2][2] != block[3][6]) {
                nextDir *= -1;
                chkRotate[3] = nextDir;
            }

            nextDir = dir;
            if (block[2][6] != block[1][2]) {
                nextDir *= -1;
                chkRotate[1] = nextDir;
                if (block[1][6] != block[0][2]) {
                    nextDir *= -1;
                    chkRotate[0] = nextDir;
                }
            }
        } else {
            // 3
            if (block[3][6] != block[2][2]) {
                nextDir *= -1;
                chkRotate[2] = nextDir;

                if (block[2][6] != block[1][2]) {
                    nextDir *= -1;
                    chkRotate[1] = nextDir;

                    if (block[1][6] != block[0][2]) {
                        nextDir *= -1;
                        chkRotate[0] = nextDir;
                    }
                }
            }
        }
    }

    public static void rotate(int num, int dir) {
        int [] newBlock = new int[8];

        if (dir == -1) { // reverse
            int tmp = block[num][0];
            for (int i = 1; i < 8; i++) {
                newBlock[i - 1] = block[num][i];
            }
            newBlock[7] = tmp;
        } else { // 
            int tmp = block[num][7];
            for (int i = 0; i < 7; i++) {
                newBlock[i + 1] = block[num][i];
            }
            newBlock[0] = tmp;
        }

        for (int i = 0; i < 8; i++) {
            block[num][i] = newBlock[i];
        }
    }

    public static void printBlock(int k, int [] chkRotate) {
        System.out.println();
        System.out.println("k=" + k);
        for (int i = 0; i < 4; i++) {
            System.out.print(chkRotate[i] + " ");
        }
        System.out.println();

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                System.out.print(block[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }
    }
}
