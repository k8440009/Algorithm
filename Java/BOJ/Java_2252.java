import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Java_2252 {
    static ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
    static int [] inDeg;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] tokens = br.readLine().split(" ");
        ArrayList<Integer> results = new ArrayList<>();
        int N = Integer.parseInt(tokens[0]);
        int M = Integer.parseInt(tokens[1]);
        Queue <Integer> q = new LinkedList<>();

        inDeg = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < M; i++) {
            tokens = br.readLine().split(" ");
            int a = Integer.parseInt(tokens[0]);
            int b = Integer.parseInt(tokens[1]);

            adj.get(a).add(b);
            inDeg[b] += 1;
        }

        for (int i = 1; i <= N; i++) {
            if (inDeg[i] == 0) {
                q.add(i);
            }
        }

        while(!q.isEmpty()) {
            int cur = q.poll();

            results.add(cur);
            for (int node : adj.get(cur)) {
                inDeg[node] -= 1;
                if (inDeg[node] == 0) {
                    q.add(node);
                }
            }
        }

        for (int result : results) {
            System.out.print(result + " ");
        }
        System.out.println();
    }
}
