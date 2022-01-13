import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_1181 {
    static int N, S;
    static int count = 0;
    static int [] numbers;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] param = br.readLine().split(" ");
        String [] tokens = br.readLine().split(" ");

        N = Integer.parseInt(param[0]);
        S = Integer.parseInt(param[1]);

        numbers = new int [N];

        for (int i = 0; i < N; i++){
            numbers[i] = Integer.parseInt(tokens[i]);
        }

        dfs(0, 0);

        System.out.println(count);
    }

    public static void dfs(int idx, int sum){
        if (idx == N){
            return ;
        }

        if (sum +  numbers[idx] == S)
            count += 1;
        
        dfs(idx + 1, sum + numbers[idx]);

        dfs(idx + 1, sum);
    }
}
