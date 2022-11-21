import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Java_1920_2_2 {
    public static void main(String[] args) throws IOException{
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
        }

        for (int m = 0; m < M; m++) {
            int lo = 0;
            int hi = N - 1;
            int basis = numbers[m];
            boolean flag = false;
            //lo < mid < hi
            while(lo <= hi) {
                int mid = (lo + hi) / 2;

                if (basis > inputs[mid]) {
                    lo = mid + 1;
                } else if (basis < inputs[mid]) {
                    hi = mid - 1;
                } else {
                    flag = true;
                    break;
                }
            }

            if (flag == true) {
                System.out.println("1");
            } else {
                System.out.println("0");
            }
        }
    }
}
