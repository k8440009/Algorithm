import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_2805 {
    static int N, M;
    static int [] tree;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] param = br.readLine().split(" ");
        String [] tokens = br.readLine().split(" ");

        N = Integer.parseInt(param[0]); // tree_count
        M = Integer.parseInt(param[1]); // min_size
        tree = new int[N];

        for (int i = 0; i < N; i++) {
            tree[i] = Integer.parseInt(tokens[i]);
        }

        long lo = 0;
        long hi = 1000000000L;

        while(lo + 1 < hi){
            long mid = (lo + hi) / 2;
            long sum = 0;
            for (int i = 0; i < N; i++){
                if (tree[i] > mid)
                    sum += (tree[i] - mid);
            }
            // mid로 M이상의 길이를 가져갈 수 있음
            if (sum >= M){
                lo = mid;
            } else {
                hi = mid;
            }
        }
        System.out.println(lo);
    }
}