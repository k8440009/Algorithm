import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class Java_1260 {
    static int N, M, V;
    static ArrayList<Integer> arr[] = null;
    static boolean [] visited;
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        V = Integer.parseInt(tokens[2]);

        arr = new ArrayList[N + 1];

        for (int i = 1; i <= N; i++){
            arr[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++){
            tokens = br.readLine().split(" ");
            
            arr[Integer.parseInt(tokens[0])].add(Integer.parseInt(tokens[1]));
            arr[Integer.parseInt(tokens[1])].add(Integer.parseInt(tokens[0]));
        }

        for (int i = 1; i <= N; i++){
            Collections.sort(arr[i]);
        }

        sb.setLength(0);
        visited = new boolean[N + 1];
        dfs(V);
        System.out.println(sb.toString());

        sb.setLength(0);
        visited = new boolean[N + 1];
        bfs(V);
        System.out.println(sb.toString());
    }

    public static void dfs(int index){
        visited[index] = true;
        sb.append(index + " ");
        for (int v : arr[index]){
            if (!visited[v]) {
                dfs(v);
            }
        }
    }

    public static void bfs(int index){
        visited[index] = true;
        Queue <Integer> queue = new LinkedList<>();
        queue.add(index);

        while(!queue.isEmpty()){
            int a = queue.poll();
            sb.append(a + " ");
            for (int v : arr[a]){
                if (!visited[v]){
                    visited[v] = true;
                    queue.add(v);
                }
            }
        }
    }

}
