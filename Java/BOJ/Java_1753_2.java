import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

/**
 * 다익스트라 우선순위 사용 구현
 * O(ElogV)
 * 
 * @since 2022-09-07
 * @author SungSoo Lee
 */
class Node_1753_2 implements Comparable<Node_1753_2>{ // 비용, 간선번호
    int weight;
    int end; 

    Node_1753_2(int weight, int end) {
        this.weight = weight;
        this.end = end;
    }

    @Override
    public int compareTo(Node_1753_2 o) {
        if (this.weight > o.weight) {
            return 1;
        } else if (this.weight < o.weight) {
            return -1;
        } else {
            if (this.end > o.end) {
                return -1;
            } else if (this.end < o.end) {
                return 1;
            } else {
                return 0;
            }
        }
    }


}

public class Java_1753_2 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        ArrayList<ArrayList<Node_1753_2>> adj = new ArrayList<>();
        String [] tokens = br.readLine().split(" ");

        int V = Integer.parseInt(tokens[0]);
        int E = Integer.parseInt(tokens[1]);
        int [] dist = new int[V + 1]; // 최단거리 테이블
        // boolean [] fix = new boolean[V + 1]; // 방문
        
        for (int i = 0; i <= V; i++) {
            adj.add(new ArrayList<>());
        }

        int start = Integer.parseInt(br.readLine());
        for (int i = 0; i < E; i++) {
            String [] data = br.readLine().split(" ");
            
            int u = Integer.parseInt(data[0]);
            int v = Integer.parseInt(data[1]);
            int w = Integer.parseInt(data[2]);
            
            adj.get(u).add(new Node_1753_2(w, v));
        }

        for (int v = 1; v <= V; v++) {
            dist[v] = Integer.MAX_VALUE;
        }

        PriorityQueue <Node_1753_2> priorityQueue = new PriorityQueue<>();

        dist[start] = 0;
        // 0, 시작점
        priorityQueue.add(new Node_1753_2(dist[start], start));
        while(!priorityQueue.isEmpty()) {
            Node_1753_2 cur = priorityQueue.poll();

            if (dist[cur.end] != cur.weight) {
                continue;
            }

            for (Node_1753_2 nxt : adj.get(cur.end)) {
                if (dist[nxt.end] <= dist[cur.end] + nxt.weight) {
                    continue;
                }

                dist[nxt.end] = dist[cur.end] + nxt.weight;
                priorityQueue.add(new Node_1753_2(dist[nxt.end], nxt.end));
            }
        }

        for (int i = 1; i <= V; i++) {
            int d = dist[i];
            if (d == Integer.MAX_VALUE) {
                System.out.println("INF");
            } else {
                System.out.println(d);
            }
        }
    }
}
