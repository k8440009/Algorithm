public class Java_92344 {
    public static void main(String[] args) {
        Solution_92344 test = new Solution_92344();

        // int[][] board = {
        //     {5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5}

        // };
        // int [][] skill = {
        //      {1,0,0,3,4,4}
        //     ,{1,2,0,2,3,2}
        //     ,{2,1,0,3,1,2}
        //     ,{1,0,1,3,3,1}
        // };

        int [][] board = {
            {1,2,3},{4,5,6},{7,8,9}
        };

        int [][] skill = {
            {1,1,1,2,2,4},{1,0,0,1,1,2},{2,2,0,2,0,100}
        };
        int answer = test.solution(board, skill);
        System.out.println(answer);
        // test.solution(board, skill);
        // [[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5]]
    }
}

class Solution_92344 {
    public int solution(int[][] board, int[][] skills) {
        int answer = 0;

        int maxSizeR = board.length + 1;
        int maxSizeC = board[0].length + 1;
        int [][] prefixSum = new int [maxSizeR][maxSizeC];

        // for (int r = 0; r < board.length; r++) {
        //     for (int c = 0; c < board[0].length; c++) {
        //         prefixSum[r][c] = board[r][c];
        //     }
        // }

        for (int [] skill : skills) {

            int type = skill[0];
            int r1 = skill[1];
            int c1 = skill[2];
            int r2 = skill[3];
            int c2 = skill[4];
            int degree = skill[5];

            if (type == 1) {
                degree *= -1;
            }

            prefixSum[r1][c1] += degree;
            prefixSum[r1][c2 + 1] += (degree * (-1));
            prefixSum[r2 + 1][c1] += (degree * (-1));
            prefixSum[r2 + 1][c2 + 1] += degree;
            
        }
        // System.out.println("test0");
        // printBoard(prefixSum);

        for (int r = 0; r < maxSizeR; r++) {
            for (int c = 0; c < maxSizeC - 1; c++) {
                prefixSum[r][c + 1] += prefixSum[r][c];
            }
        }
        // System.out.println("test1");
        // printBoard(prefixSum);

        // 열 기준 누적합
        for (int c = 0; c < maxSizeC; c++) {
            for (int r = 0; r < maxSizeR - 1; r++) {
                prefixSum[r + 1][c] += prefixSum[r][c];
            }
        }
        // System.out.println("test2");
        // printBoard(prefixSum);

        for (int r = 0; r < board.length; r++) {
            for (int c = 0; c < board[0].length; c++) {
                prefixSum[r][c] += board[r][c];
                
                if (prefixSum[r][c] > 0)
                    answer += 1;
            }
        }
        // System.out.println("test3");
        // printBoard(prefixSum);

        return answer;
    }

    public void printBoard (int [][] src) {
        for (int r = 0; r < src.length; r++) {
            for (int c = 0; c < src[0].length; c++) {
                System.out.print(src[r][c] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}