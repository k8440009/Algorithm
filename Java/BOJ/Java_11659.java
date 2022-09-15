import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_11659 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String [] tokens = br.readLine().split(" ");
        int N = Integer.parseInt(tokens[0]);
        int M = Integer.parseInt(tokens[1]);

        int [] prefixSum = new int [N + 1];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            int a = Integer.parseInt(tokens[i]);
            
            prefixSum[i + 1] = prefixSum[i] + a;
        }

        for (int i = 0; i < M; i++) {
            tokens = br.readLine().split(" ");

            int a = Integer.parseInt(tokens[0]);
            int b = Integer.parseInt(tokens[1]);

            System.out.println(prefixSum[b] - prefixSum[a-1]);
        }
    }
}
