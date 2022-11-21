import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_2003_1 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] tokens = br.readLine().split(" ");
        int N = Integer.parseInt(tokens[0]);
        int M = Integer.parseInt(tokens[1]);

        int [] arr = new int [N];

        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(tokens[i]);
        }

        int start = 0;
        int end = 0;
        long sum = 0;
        long result = 0;
        while(true) {
            if (sum >= M) {
                sum -= arr[start];
                start += 1;
            } else if (end == N){
                break;
            } else {
                sum += arr[end];
                end += 1;
            }

            if (sum == M) {
                result += 1;
            }
        }

        System.out.println(result);
    }
}
