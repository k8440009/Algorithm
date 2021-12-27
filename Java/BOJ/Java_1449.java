import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Java_1449 {
    static int N, L;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] param = br.readLine().split(" ");
        String [] tokens = br.readLine().split(" ");

        N = Integer.parseInt(param[0]);
        L = Integer.parseInt(param[1]);

        ArrayList <Integer> arrayList = new ArrayList<>();
        for (int i = 0; i < N; i++){
            arrayList.add(Integer.parseInt(tokens[i]));
        }
        Collections.sort(arrayList);

        int cnt = 1;
        int cur = arrayList.get(0);
        int next = cur + L;
        for (int i = 0; i < N; i++){
            cur = arrayList.get(i);
            if (cur >= next){
                next = cur + L;
                cnt += 1;
            }
        }
        System.out.println(cnt);
    }
}
