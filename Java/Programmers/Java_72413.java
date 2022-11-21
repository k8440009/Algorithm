import java.util.ArrayList;
import java.util.PriorityQueue;

public class Java_72413 {
    public static void main(String[] args) {
        Solution_72413 test = new Solution_72413();
        int [][] fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
        
        System.out.println(test.solution(6, 4, 6, 2, fares));
    }
}

/**
 * 다익스트라 응용
 * 1. 모든 점의 최소 거리를 구하기 위해 전체 노드 다익스트라
 * 2. 2차원 배열로 저장
 * 3. 전체 노드 루프돌면서 최솟값 구함
 * 1) 각각 : totalDist[start][a] + totalDist[start][b]
 * 2) 중간 : totalDist[start][i] + totalDist[i][a] + totalDist[i][b]
 */

class Node_72413 implements Comparable<Node_72413>{ // 비용, 간선번호
    int weight;
    int end; 

    Node_72413(int weight, int end) {
        this.weight = weight;
        this.end = end;
    }

    @Override
    public int compareTo(Node_72413 o) {
        return this.weight - o.weight;
    }
}

class Solution_72413 {
    static ArrayList<ArrayList<Node_72413>> adj = new ArrayList<>();

    int [][] totalDist = null;
    int N = 0;
    public int solution(int n, int start, int a, int b, int[][] fares) {
        int answer = 0;

        N = n;
        totalDist = new int[N + 1][N + 1];

        for (int i = 0; i <= N; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < fares.length; i++) {
            int u = fares[i][0];
            int v = fares[i][1];
            int w = fares[i][2];

            adj.get(u).add(new Node_72413(w, v));
            adj.get(v).add(new Node_72413(w, u));
        }

        for (int i = 1; i <= N; i++) {
            dijkstra(i);
        }

        int minPath = totalDist[start][a] + totalDist[start][b];
        for (int i = 1; i <= N; i++) {
            minPath = Math.min(totalDist[start][i] + totalDist[i][b] + totalDist[i][a], minPath);
        }
        answer = minPath;
        return answer;
    }

    public void dijkstra(int start) {
        PriorityQueue <Node_72413> priorityQueue = new PriorityQueue<>();

        int [] dist = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            dist[i] = Integer.MAX_VALUE;
        }

        dist[start] = 0;
        priorityQueue.add(new Node_72413(dist[start], start));

        while(!priorityQueue.isEmpty()) {
            Node_72413 cur = priorityQueue.poll();

            if (dist[cur.end] != cur.weight) {
                continue;
            }

            for (Node_72413 next : adj.get(cur.end)) {
                if (dist[next.end] <= dist[cur.end] + next.weight) {
                    continue;
                }
                dist[next.end] = dist[cur.end] + next.weight;
                priorityQueue.add(new Node_72413(dist[next.end], next.end));
            }
        }

        for (int j = 1; j <= N; j++) {
            totalDist[start][j] = dist[j];
            totalDist[j][start] = dist[j];
        }
    }
}