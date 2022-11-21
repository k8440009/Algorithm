import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_2003 {
    static int N, M;
    static int arr[];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] param = br.readLine().split(" ");
        String [] tokens = br.readLine().split(" ");

        N = Integer.parseInt(param[0]);
        M = Integer.parseInt(param[1]);

        arr = new int [N];
        for (int i = 0; i < tokens.length; i++){
            arr[i] = Integer.parseInt(tokens[i]);
        }

        int st = 0;
        int ed = 0;
        int sum = 0;
        int result = 0;
        while (true) {
            if (sum >= M){
                sum -= arr[st];
                st += 1;
            } else if (ed == N){
                break;
            } else {
                sum += arr[ed];
                ed += 1;
            }
            
            if (sum == M)
                result += 1;
    
        }
        System.out.println(result);
    }
}