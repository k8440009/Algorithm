public class Java_60059 {
    public static void main(String[] args) {
        Solution_60059 test = new Solution_60059();
        
        System.out.println("test1");
        int [][] key1 = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
        int [][] lock1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
        System.out.println(test.solution(key1, lock1));
    }
}

class Solution_60059{
    static int N;
    static int M;
    static boolean answer = false;

    int [][] key;
    int [][] lock;
    public boolean solution(int[][] tmpKey, int[][] tmpLock) {

        N = tmpKey.length;
        M = tmpLock.length;

        key = new int [N][N];
        lock = new int [M][M];

        copyBoard(key, tmpKey);
        copyBoard(lock, tmpLock);
        /**
         * 1. 자물쇠 홈을 끼울 지점을 선택
         * 2. key의 홈 기준을 선택
         * 
         * 3. newLock에 복사
         * 4. newLock에 열쇠를 끼워 넣는다.
         */
        for (int lr = 0; lr < N; lr++) {
            for (int lc = 0; lc  < N; lc++) {
                for (int kr = 0; kr < M; kr++) {
                    for (int kc = 0; kc < M; kc++) {
                        dfs(lr, lc, kr, kc);
                    }
                }
            }
        }
        return answer;
    }

    void dfs(int lr, int lc, int kr, int kc) {
        if (answer) {
            return ;
        }

        int [][] newLock = new int [80][80];

        for (int r = 0; r < M; r++) {
            for (int c = 0; c < M; c++) {
                newLock[30 + r][30 + c] = lock[r][c];
            }
        }

        int [][] newkey = new int [20][20];
        int [][] rotateKey = new int [20][20]; // 회전 용
        copyBoard(newkey, key);
        copyBoard(rotateKey, key);
        int cntRot = 0;
        for (int rot = 0; rot <= 3; rot++) {

            while(cntRot < rot) {
                // rotateKey(rotateKey, newkey);
                // copyBoard(newkey, rotateKey);
                cntRot += 1;
            }

            boolean flag = true;

            // for (int row = lr;)
            // for (int row = kr; row < M; row++) {
            //     for (int col = kc; col < M; col++) {

            //     }
            // }

            // for (int r = M - 1; r >= 0; r--) {
            //     for (int c = M - 1; c >= 0; c--) {
                    
            //         int row = r + 0;
            //         int column = c + 0;
            //     }
            // }
            // for (int r = M-1; r >= 0; r--) {
            //     for (int c = M-1; c >=0; c--) {
            //         newLock[30 + r][30 + c] += key[r][c];
            //         if (newLock[30 + r][30 + c] != 1) {
            //             flag = false;
            //             break;
            //         }
            //     }

            //     if (!flag) {
            //         break;
            //     }
            // }

            if (flag) {
                answer = true;
                break;
            }
        }
    }

    void rotateKey(int [][] desc, int [][] src) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                desc[r][c] = src[N - c - 1][r];
            }
        }
    }

    void copyBoard(int [][] desc, int [][] src) {
        for (int r = 0; r < desc.length; r++) {
            for (int c = 0; c < desc.length; c++) {
                desc[r][c] = src[r][c];
            }
        }
    }
}