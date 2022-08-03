import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_10974 {
    static int N;
    static int [] arr = null;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        N = n;
        int r = n;
        arr = new int [N];

        for (int i = 0; i < N; i++) {
            arr[i] = i + 1;
        }

        boolean [] visited = new boolean[N];
        int [] output = new int[N];
        // n개중 r개
        permutation(0, output, visited, r);
    }
    
    public static void permutation(int cnt, int [] output, boolean [] visited, int r) {
        if (cnt == r) {
            for (int i = 0; i < N; i++) {
                System.out.print(output[i] + " ");
            }
            System.out.println();
            return ;
        }

        for (int i = 0; i < N; i++) {
            if (visited[i] == false) {
                output[cnt] = arr[i];
                visited[i] = true;
                permutation(cnt + 1, output, visited, r);
                visited[i] = false;
            }
        }
    }
}
