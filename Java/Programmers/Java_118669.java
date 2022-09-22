import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class Java_118669 {
    public static void main(String[] args) {
        Solution_118669 test = new Solution_118669();

        int [] answer;

        System.out.println("test1");
        int [][] paths1 = {{1, 2, 3}, {2, 3, 5}, {2, 4, 2}, {2, 5, 4}, {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1}};
        int [] gates1 = {1, 3};
        int [] summits1 = {5};
        answer = test.solution(6, paths1, gates1, summits1);
        System.out.println(answer[0] + " "  + answer[1]);

        System.out.println("test2");
        int [][] paths2 = {{1, 4, 4}, {1, 6, 1}, {1, 7, 3}, {2, 5, 2}, {3, 7, 4}, {5, 6, 6}};
        int [] gates2 = {1};
        int [] summits2 = {2,3,4};
        answer = test.solution(7, paths2, gates2, summits2);
        System.out.println(answer[0] + " "  + answer[1]);

        System.out.println("test3");
        int [][] paths3 = {{1, 2, 5}, {1, 4, 1}, {2, 3, 1}, {2, 6, 7}, {4, 5, 1}, {5, 6, 1}, {6, 7, 1}};
        int [] gates3 = {3, 7};
        int [] summits3 = {1, 5};
        answer = test.solution(7, paths3, gates3, summits3);
        System.out.println(answer[0] + " "  + answer[1]);

        System.out.println("test4");
        int [][] paths4 = {{1, 3, 10}, {1, 4, 20}, {2, 3, 4}, {2, 4, 6}, {3, 5, 20}, {4, 5, 6}};
        int [] gates4 = {1, 2};
        int [] summits4 = {5};
        answer = test.solution(6, paths4, gates4, summits4);
        System.out.println(answer[0] + " "  + answer[1]);

    }
}
class Node_118669 implements Comparable <Node_118669> {
    int end;
    int weight;

    Node_118669(int weight, int end) {
        this.weight = weight;
        this.end = end;
    }

    @Override
    public int compareTo(Node_118669 o) {
        return this.weight - o.weight;
    }
}
class Solution_118669 {
    static int [] intensities;
    static ArrayList<ArrayList<Node_118669>> adj;
    static Map <Integer, Integer> summitMap;
    static Map <Integer, Integer> gateMap;
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        adj = new ArrayList<>();
        summitMap = new HashMap<>();
        gateMap = new HashMap<>();

        intensities = new int [n + 1];
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
            intensities[i] = Integer.MAX_VALUE;
        }

        for (int summit : summits) {
            summitMap.put(summit, 1);
        }

        for (int gate : gates) {
            gateMap.put(gate, 1);
        }

        Arrays.sort(summits);
        for (int [] path : paths) {
            int i = path[0];
            int j = path[1];
            int w = path[2];

            adj.get(i).add(new Node_118669(w, j));
            adj.get(j).add(new Node_118669(w, i));
        }

        PriorityQueue<Node_118669> priorityQueue = new PriorityQueue<>();
        for (int gate : gates) {
            priorityQueue.add(new Node_118669(0, gate));
            intensities[gate] = 0;
        }

        while(!priorityQueue.isEmpty()) {
            Node_118669 cur = priorityQueue.poll();

            if (intensities[cur.end] != cur.weight) {
                continue;
            }

            for (Node_118669 nxt : adj.get(cur.end)) {
                if (intensities[nxt.end] > intensities[cur.end] + nxt.weight) {
                    intensities[nxt.end] = intensities[cur.end] + nxt.weight;
                }
                priorityQueue.add(new Node_118669(intensities[nxt.end], nxt.end));
            }
        }

        int minIntensity = Integer.MAX_VALUE;
        int index = -1;
        for (int summit : summits) {
            if (intensities[summit] < minIntensity) {
                minIntensity = intensities[summit];
                index = summit;
            }
        }
        return new int [] {index, minIntensity};
    }
}