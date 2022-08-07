import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_2747 {
    static int [] dp = new int[45 + 1];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        dp[0] = 1;
        dp[1] = 1;
        System.out.println(fibo(N));
    }

    public static int fibo(int n) {
        if (n == 0) {
            return 0;
        }

        if (n == 1 || n == 2) {
            return 1;
        }

        return fibo(n - 1) + fibo(n-2);
    }
}
