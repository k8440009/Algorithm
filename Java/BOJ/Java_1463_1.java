import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_1463_1 {
    static int maxSize = 1000000 + 1;
    static int [] dp = new int [maxSize];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i - 1] + 1;
            if (i % 2 == 0) {
                dp[i] = Math.min(dp[i / 2] + 1, dp[i]);
            }

            if (i % 3 == 0) {
                dp[i] = Math.min(dp[i / 3] + 1, dp[i]);
            }
        }

        System.out.println(dp[N]);
    }
}