import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_2579 {
    static int [][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int [] arr = new int[N + 1];
        dp = new int[N + 1][3];

        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        /**
         * N이 1일때, arr[2], dp[2][3] 까지만 만들어지므로
         * 런타임 에러 발생
         * 
         * @Since  : 2022-09-03
         * @Author : SungsooLee
         */
        int answer = -1;
        if (N == 1) {
            answer = arr[1];
        } else {
            dp[1][1] = arr[1];
            dp[1][2] = 0;
    
            dp[2][1] = arr[2];
            dp[2][2] = arr[1] + arr[2];
    
            for (int n = 3; n <= N; n++) {
                dp[n][1] = Math.max(dp[n-2][1], dp[n-2][2]) + arr[n];
                dp[n][2] = dp[n-1][1] + arr[n];
            }

            answer = Math.max(dp[N][1], dp[N][2]);
        }
        System.out.println(answer);
    }
}
