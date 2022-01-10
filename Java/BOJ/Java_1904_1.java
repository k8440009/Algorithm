import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_1904_1 {
    static int N;
    static long [] dp;
    static long div = 15746;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] param = br.readLine().split(" ");

        N = Integer.parseInt(param[0]);
        dp = new long [N + 1];

        for (int i = 0; i <= N; i++){
            dp[i] = -1;
        }
        System.out.println(makeZeroOneTile(N));
    }

    public static long makeZeroOneTile(int size){
        if (size == 1){
            return 1;
        } else if (size == 2){
            return 2;
        }
        if (dp[size] != -1){
            return dp[size];
        }

        dp[size] = makeZeroOneTile(size - 1) + makeZeroOneTile(size - 2);
        dp[size] %= div;
        return dp[size];
    }
}
