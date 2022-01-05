import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

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

        int start = 0, end = 0;
        int sum = arr[0];
        int cnt = 0;
        while (start <= end){

            if (end == N-1) {
                break;
            }
            
            if (sum <= M){
                end += 1;
                sum += arr[end];

                if (sum == M){
                    cnt += 1;
                }

            } else{
                sum -= arr[start];
                start += 1;
            }
        }
        System.out.println(cnt);
    }
}