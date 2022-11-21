import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class Java_2075 {
    static int N;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] param = br.readLine().split(" ");
        PriorityQueue <Integer> pq = new PriorityQueue<>();

        N = Integer.parseInt(param[0]);
        for (int i = 0; i < N; i++){
            String [] tokens = br.readLine().split(" ");
            for (int j = 0; j < N; j++){
                pq.add(Integer.parseInt(tokens[j]));
            }

            while(true) {
                if (pq.size() == N)
                    break;
                pq.poll();
            }
        }
        System.out.println(pq.poll());
    }
}