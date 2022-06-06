import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

class Node {
    int node;
    int cnt;
    
    Node (int node, int cnt) {
        this.node = node;
        this.cnt = cnt;
    }
}
public class Java_2644 {
    static int N, X, Y, Z, findLength = -1;
    static ArrayList <ArrayList<Integer>> arrayList = new ArrayList<ArrayList<Integer>>();
    static Queue <Node> queue = new LinkedList<Node>();
    static boolean visited[] = null;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String params1 = br.readLine();
        N = Integer.parseInt(params1);

        for (int n = 0; n < N; n++) {
            arrayList.add(new ArrayList<Integer>());
        }
        visited = new boolean[N];
        
        String [] params2 = br.readLine().split(" ");
        X = Integer.parseInt(params2[0]) - 1;
        Y = Integer.parseInt(params2[1]) - 1;

        String params3 = br.readLine();
        Z = Integer.parseInt(params3);

        for (int z = 0; z < Z; z++) {
            String [] tokens = br.readLine().split(" ");
            int x, y;
            x = Integer.parseInt(tokens[0]) - 1;
            y = Integer.parseInt(tokens[1]) - 1;

            arrayList.get(x).add(y);
            arrayList.get(y).add(x);
        }

        queue.add(new Node(X, 0));
        visited[X] = true;
        bfs();
        System.out.println(findLength);
    }

    public static void bfs() {
        while (!queue.isEmpty()) {
            Node data = queue.poll();
            if (data.node == Y) {
                findLength = data.cnt; 
                break;
            }

            for (Integer node : arrayList.get(data.node)){
                if (visited[node] == true)
                    continue;
                
                queue.add(new Node(node, data.cnt + 1));
                visited[node] = true;
            }
        }
    }
}