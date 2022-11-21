import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class Tuple implements Comparable<Tuple> {
    int a, b, cost;
    Tuple(int a, int b, int cost) {
        this.a = a;
        this.b = b;
        this.cost = cost;
    }
    @Override
    public int compareTo(Tuple o) {
        return this.cost - o.cost;
    }
}

public class Java_1197_1 {
    static ArrayList<Tuple> edges = new ArrayList<>();
    static int [] p = new int [10005];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] tokens = br.readLine().split(" ");
        int V = Integer.parseInt(tokens[0]);
        int E = Integer.parseInt(tokens[1]);
        int answer = 0;
        int cnt = 0;
        // union find setting
        Arrays.fill(p, -1);

        for (int i = 0; i < E; i++) {
            tokens = br.readLine().split(" ");

            int a = Integer.parseInt(tokens[0]);
            int b = Integer.parseInt(tokens[1]);
            int c = Integer.parseInt(tokens[2]);

            edges.add(new Tuple(a, b, c));
        }
        
        Collections.sort(edges);

        for (Tuple tuple : edges) {
            if (!is_diff_group(tuple.a, tuple.b)) {
                continue;
            }
            answer += tuple.cost;
            cnt += 1;

            if (cnt == V - 1) {
                break;
            }
        }
        System.out.println(answer);
    }
    // Union Find 함수
    // find
    static int find (int x) {
        if (p[x] < 0) {
            return x;
        }
        return p[x] = find(p[x]);
    }
    // merge
    static boolean is_diff_group(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) {
            return false;
        }

        if (p[u] == p[v]) {
            p[u] -= 1;
        }

        if (p[u] < p[v]) {
            p[v] = u;
        } else {
            p[u] = v;
        }
        return true;
    }
}