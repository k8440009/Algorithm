import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

/**
 * 다익스트라 우선순위 없이 구현
 * O(V^2 + E)
 * 
 * @since 2022-09-06
 * @author SungSoo Lee
 */
class Node_1753_1 { // 비용, 간선번호
    int weight;
    int end; 

    Node_1753_1(int weight, int end) {
        this.weight = weight;
        this.end = end;
    }
}

public class Java_1753_1 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        ArrayList<ArrayList<Node_1753_1>> adj = new ArrayList<>();
        String [] tokens = br.readLine().split(" ");

        int V = Integer.parseInt(tokens[0]);
        int E = Integer.parseInt(tokens[1]);
        int [] dist = new int[V + 1]; // 최단거리 테이블
        boolean [] fix = new boolean[V + 1]; // 방문
        
        for (int i = 0; i <= V; i++) {
            adj.add(new ArrayList<>());
        }

        int start = Integer.parseInt(br.readLine());
        for (int i = 0; i < E; i++) {
            String [] data = br.readLine().split(" ");
            
            int u = Integer.parseInt(data[0]);
            int v = Integer.parseInt(data[1]);
            int w = Integer.parseInt(data[2]);
            
            adj.get(u).add(new Node_1753_1(w, v));
        }

        for (int v = 1; v <= V; v++) {
            dist[v] = Integer.MAX_VALUE;
        }

        int u = start;
        dist[u] = 0;
        while(true) {
            
        }

        // int u = start;
        // dist[u] = 0;
        // while(true) {
        //     int idx = -1;

        //     for (int v = 1; v <= V; v++) {
        //         if (fix[v]) {
        //             continue;
        //         }

        //         if (idx == -1) {
        //             idx = v;
        //         } else if (dist[v] < dist[idx]){
        //             idx = v;
        //         }
        //     }

        //     if (idx == -1 || dist[idx] == Integer.MAX_VALUE) {
        //         break;
        //     }

        //     ArrayList <Node_1753_1> arrayList = adj.get(idx);
        //     fix[idx] = true;
        //     for (Node_1753_1 node : arrayList) {
        //         dist[node.end] = Math.min(dist[node.end], dist[idx] + node.weight);
        //     }
        // }

        // for (int i = 1; i <= V; i++) {
        //     int d = dist[i];
        //     if (d == Integer.MAX_VALUE) {
        //         System.out.println("INF");
        //     } else {
        //         System.out.println(d);
        //     }
        // }
    }
}
