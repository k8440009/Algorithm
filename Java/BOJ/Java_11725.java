import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Java_11725 {
    static ArrayList<ArrayList<Integer>> adj;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        adj = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            adj.add(new ArrayList<>());
        }
        
        for (int i = 0; i < N - 1; i++) {
            String [] tokens = br.readLine().split(" ");
            int a = Integer.parseInt(tokens[0]);
            int b = Integer.parseInt(tokens[1]);

            adj.get(a).add(b);
            adj.get(b).add(a);
        }

        int [] nodeRoot = new int[adj.size()];
        boolean [] visited = new boolean[adj.size()];

        visited[1] = true;
        dfs(1, visited, nodeRoot);

        for (int i = 2; i <= N; i++) {
            System.out.println(nodeRoot[i]);
        }
    }

    public static void dfs(int now, boolean [] visited, int [] nodeRoot) {

        visited[now] = true;
        for (int node : adj.get(now)) {
            if (visited[node] == false) {
                nodeRoot[node]  = now;
                dfs(node, visited, nodeRoot);
            }
        }
    }
}
