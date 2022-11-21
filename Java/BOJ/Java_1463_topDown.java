import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_1463_topDown {
    static int X;
    static int [] dp;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        X = Integer.parseInt(br.readLine());

        dp = new int [X + 1];
        for (int i = 0; i < dp.length; i++){
            dp[i] = -1;
        }

        System.out.println(topDown(X));
    }


    public static int topDown(int n){
        if (n == 1){
            return 0;
        }
        if (dp[n] != -1){
            return dp[n];
        }
        dp[n] = topDown(n-1) + 1;
        if (n % 3 == 0){
            int result = topDown(n / 3) + 1;
            if (dp[n] > result){
                dp[n] = result;
            }
        }
        if (n % 2 == 0){
            int result = topDown(n / 2) + 1;
            if (dp[n] > result){
                dp[n] = result;
            }
        }
        return dp[n];
    }
}
