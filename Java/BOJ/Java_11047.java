import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Java_11047 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> arr = new ArrayList<>();
        String [] tokens = br.readLine().split(" ");
        int N = Integer.parseInt(tokens[0]);
        int K = Integer.parseInt(tokens[1]);

        for (int i = 0; i < N; i++) {
            arr.add(Integer.parseInt(br.readLine()));
        }
        Collections.sort(arr, Collections.reverseOrder());

        int k = K;
        int index = 0;
        int cnt = 0;
        while(true) {
            if (index == arr.size() || k == 0) {
                break;
            }

            int num = arr.get(index);
            if (num > k) {
                index+= 1;
            } else {
                cnt += (k / num);
                k = k % num;
            }
        }
        System.out.println(cnt);
    }
}
