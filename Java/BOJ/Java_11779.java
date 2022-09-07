import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;

/**
 * 1. 다익스트라 최단거리
 * 2. 경로 복원
 * 
 * @since 2022-09-07
 * @author SungSoo Lee
 */
class Node_11779 implements Comparable<Node_11779>{ // 비용, 간선번호
    int weight;
    int end; 

    Node_11779(int weight, int end) {
        this.weight = weight;
        this.end = end;
    }

    @Override
    public int compareTo(Node_11779 o) {
        return this.weight - o.weight;
    }
}

public class Java_11779 {
    static ArrayList<ArrayList<Node_11779>> adj = new ArrayList<>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        int [] dist = new int[N + 1];
        int [] prev = new int[N + 1];

        for (int i = 0; i <= N; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 1; i <= N; i++) {
            dist[i] = Integer.MAX_VALUE;
        }

        String [] tokens = null;
        for (int i = 0; i < M; i++) {
            tokens = br.readLine().split(" ");

            int u = Integer.parseInt(tokens[0]);
            int v = Integer.parseInt(tokens[1]);
            int w = Integer.parseInt(tokens[2]);

            adj.get(u).add(new Node_11779(w, v));
        }
        tokens = br.readLine().split(" ");

        int start = Integer.parseInt(tokens[0]);
        int end = Integer.parseInt(tokens[1]);

        PriorityQueue <Node_11779> priorityQueue = new PriorityQueue<>();

        dist[start] = 0;
        priorityQueue.add(new Node_11779(dist[start], start));

        while(!priorityQueue.isEmpty()) {
            Node_11779 cur = priorityQueue.poll();

            if (dist[cur.end] != cur.weight) {
                continue;
            }

            for (Node_11779 next : adj.get(cur.end)) {
                if (dist[next.end] <= dist[cur.end] + next.weight) {
                    continue;
                }
                dist[next.end] = dist[cur.end] + next.weight;
                priorityQueue.add(new Node_11779(dist[next.end], next.end));
                prev[next.end] = cur.end;
            }
        }

        System.out.println(dist[end]);

        ArrayList<Integer> paths = new ArrayList<>();
        int cur = end;
        while(cur != start) {
            paths.add(cur);
            cur = prev[cur];
        }
        paths.add(start);

        Collections.reverse(paths);
        System.out.println(paths.size());
        for (int path : paths) {
            System.out.print(path + " ");
        }
    }
}
