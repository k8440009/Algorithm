import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Java_11724_1_1 {
    static boolean [] visited;
    static int ConnectedCompCnt = 0;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] tokens = br.readLine().split(" ");

        int N = Integer.parseInt(tokens[0]);
        int M = Integer.parseInt(tokens[1]);

        ArrayList<ArrayList <Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            tokens = br.readLine().split(" ");
            int u = Integer.parseInt(tokens[0]);
            int v = Integer.parseInt(tokens[1]);

            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        visited = new boolean[N + 1];
        for (int i = 1; i <= N; i++) {
            if (visited[i] == false) {
                bfs(i, graph);
            }
        }
        System.out.println(ConnectedCompCnt);
    }

    public static void bfs(int start, ArrayList<ArrayList<Integer>> graph) {
        Queue <Integer> que = new LinkedList<>();
        que.add(start);
        visited[start] = true;
        ConnectedCompCnt += 1;

        while(!que.isEmpty()) {
            int node = que.poll();
            ArrayList<Integer> vertexs = graph.get(node);

            for (int vertex : vertexs) {
                if (visited[vertex] == true){
                    continue;
                }

                que.add(vertex);
                visited[vertex] = true;
            }
        }
    }
}
