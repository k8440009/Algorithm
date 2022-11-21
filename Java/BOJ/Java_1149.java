import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_1149 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        /**
         * Dp[i][0] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 빨강
         * Dp[i][1] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 초록
         * Dp[i][2] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 파랑
         * 
         * @author SungsooLee
         * @since 2022-09-04
         */
        int N = Integer.parseInt(br.readLine());
        int [][] arr = new int [N + 1][3];
        int [][] dp = new int[N + 1][3];

        for (int i = 1; i <= N; i++) {
            String [] tokens = br.readLine().split(" ");

            arr[i][0] = Integer.parseInt(tokens[0]);
            arr[i][1] = Integer.parseInt(tokens[1]);
            arr[i][2] = Integer.parseInt(tokens[2]);
        }

        dp[1][0] = arr[1][0];
        dp[1][1] = arr[1][1];
        dp[1][2] = arr[1][2];

        for (int i = 2; i <= N; i++) {
            dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
            dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
            dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
        }
        int answer = Math.min(Math.min(dp[N][0], dp[N][1]), dp[N][2]);

        System.out.println(answer);
    }
}
