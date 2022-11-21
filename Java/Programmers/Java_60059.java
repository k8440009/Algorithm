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
    /**
     * 1. 자물쇠길이 + 키 * 2 + 2
     * 2. map에 lock 배열의 값을 위치에 맞게 입력
     * 3. 키가 자물쇠에 맞는지 체크
     * 4. 안 맞으면 rotate
     * @param key
     * @param lock
     * @return
     */
    public boolean solution(int[][] key, int[][] lock) {

        M = key.length;
        N = lock.length;
        int len = N + M * 2 + 2;

        int [][] extended = new int [len][len];

        for (int r = M - 1; r < M + N - 1; r++) {
            for (int c = M - 1; c < M + N - 1; c++) {
                extended[r][c] = lock[r - (M - 1)][c - (M - 1)];
            }
        }

        for (int i = 0; i < 4; i++) {
            if (check(extended, key)) {
                return true;
            }
            rotate(key);
        }

        return false;
    }

    static boolean check(int [][] extended, int [][] key) {
        int maxLength = extended.length;
        for (int r = 0; r < maxLength - M + 1; r++) {
            for (int c = 0; c < maxLength - M + 1; c++) {

                // map에 key를 더함
                for (int kr = 0; kr < M; kr++) {
                    for (int kc = 0; kc < M; kc++) {
                        extended[r + kr][c + kc] += key[kr][kc];
                    }
                }

                // 자물쇠 부분 체크
                boolean flag = true;
                for (int kr = M - 1; kr < N + M - 1; kr++) {
                    for (int kc = M - 1; kc < N + M - 1; kc++) {
                        if (extended[kr][kc] != 1) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) {
                        break;
                    }
                }

                if (flag)
                    return true;

                // 복구
                for (int kr = 0; kr < M; kr++) {
                    for (int kc = 0; kc < M; kc++) {
                        extended[r + kr][c + kc] -= key[kr][kc];
                    }
                }
            }
        }
        return false;
    }

    static void rotate(int [][] key) {
        int len = key.length;
        int [][] tmp = new int [len][len];

        for (int r = 0; r  < len; r++) {
            for (int c = 0; c < len; c++) {
                tmp[r][c] = key[len - c - 1][r];
            }
        }

        for (int r = 0; r < len; r++) {
            for (int c = 0; c < len; c++) {
                key[r][c] = tmp[r][c];
            }
        }
    }
}