import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_2193 {
    static int N;
    static int cnt = 0;
    static int [][] dp;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] param = br.readLine().split(" ");
        N = Integer.parseInt(param[0]);

        dp = new int [N + 1][2];
        for (int i = 0; i < dp.length; i++){
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        System.out.println(makeZeroOneNumber(N-1, 0, "1"));
    }

    public static int makeZeroOneNumber(int size, int digit, String num){
        if (size == 0){
            return 1;
        }
        if (dp[size][digit] != -1){
            return dp[size][digit];
        }
        if (digit == 1){
            dp[size][digit] = + makeZeroOneNumber(size - 1, 0, num  + 0);
        } else{
            dp[size][digit] = makeZeroOneNumber(size - 1, 1, num + 1) + makeZeroOneNumber(size - 1, 0, num  + 0);
        }
        return dp[size][digit];
    }
}