import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_11660 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] tokens = br.readLine().split(" ");
        int N = Integer.parseInt(tokens[0]);
        int M = Integer.parseInt(tokens[1]);

        // prefixSum[i][j] = arr 0 ~ i-1 행, 0 ~ j-1열 모든 원소의 합
        // prefixSum[r2+1][c2+1] - prefixSum[r1][c2+1] - prefixSum[r2+1][c1] + prefixSum[r1][c1]
        int [][] prefixSum = new int [N + 1][N + 1];

        for (int r = 0; r < N; r++) {
            tokens = br.readLine().split(" ");
            for (int c = 0; c < N; c++) {
                int num = Integer.parseInt(tokens[c]);

                prefixSum[r + 1][c + 1] = prefixSum[r + 1][c] + prefixSum[r][c + 1] - prefixSum[r][c] + num;
            }
        }

        for (int i = 0; i < M; i++) {
            tokens = br.readLine().split(" ");

            int x1 = Integer.parseInt(tokens[0]);
            int y1 = Integer.parseInt(tokens[1]);
            int x2 = Integer.parseInt(tokens[2]);
            int y2 = Integer.parseInt(tokens[3]);

            int sum = prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1];
            System.out.println(sum);
        }
    }
}
