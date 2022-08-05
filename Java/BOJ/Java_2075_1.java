import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collection;
import java.util.Collections;
import java.util.PriorityQueue;

public class Java_2075_1 {
    /**
     * 정렬하는 문제이다.
     * 힙정렬을 사용하여 적은 메모리를 사용하여 정렬을 할 수 이따.
     * 
     * @param args
     */
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        PriorityQueue <Integer> pq = new PriorityQueue<Integer>();

        for (int r = 0; r < N; r++) {
            String [] tokens = br.readLine().split(" ");
            for (int c = 0; c < N; c++) {
                pq.add(Integer.parseInt(tokens[c]));

                if (r != 0) {
                    pq.poll();
                }
            }
        }

        System.out.println(pq.peek());
    }
}
