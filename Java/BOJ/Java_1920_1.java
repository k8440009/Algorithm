import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Java_1920_1 {
    public static void main(String[] args)  throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String [] tokens = br.readLine().split(" ");
        int [] inputs = new int [N];
        
        for (int n = 0; n < N; n++) {
            inputs[n] = Integer.parseInt(tokens[n]);
        }

        Arrays.sort(inputs);
        
        int M = Integer.parseInt(br.readLine());
        int [] numbers = new int [M];
        tokens = br.readLine().split(" ");
        for (int m = 0; m < M; m++) {
            numbers[m] = Integer.parseInt(tokens[m]);

            int flag = Arrays.binarySearch(inputs, 0, N, numbers[m]);
            if (flag >= 0) {
                System.out.println("1");
            } else {
                System.out.println("0");
            }
        }
    }
}
