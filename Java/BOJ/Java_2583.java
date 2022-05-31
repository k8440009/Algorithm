import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_2583 {
    static int N, M, K;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] tokens = br.readLine().split(" ");
        M = Integer.parseInt(tokens[0]);
        N = Integer.parseInt(tokens[1]);
        K = Integer.parseInt(tokens[2]);

        for (int i = 0; i < K; i++){
            tokens = br.readLine().split(" ");

            Integer.parseInt(tokens[0]);
            Integer.parseInt(tokens[1]);
            Integer.parseInt(tokens[2]);
            Integer.parseInt(tokens[3]);

            
        }
    }
}