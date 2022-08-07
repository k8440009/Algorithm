import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Java_1463_2 {
    static int [] dp;
    static int totalCnt = 0;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        dp = new int [N + 1];
        Arrays.fill(dp, -1);

        System.out.println(dfs(N));
    }

    public static int dfs(int n) {
        if (n == 1) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }
        
        int result = dfs(n - 1) + 1;
        if (n % 3 == 0) {
            result = Min(result, dfs(n / 3) + 1);
        }
        if (n % 2 == 0) {
            result = Min(result, dfs(n / 2) + 1);
        }
        dp[n] = result;
        return result;
    }

    public static int Min(int a, int b) {
        if (a < b) {
            return a;
        } else {
            return b;
        }
    }
}