import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_14888 {
    static int N;
    static int [] number;
    static int [] opr;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        number = new int[N];

        String [] token = br.readLine().split(" ");
        String [] param = br.readLine().split(" ");

        for (int i = 0; i < N; i++) {
            number[i] = Integer.parseInt(token[i]);
        }
        for (int i = 0; i < 4; i++){
            opr[i] = Integer.parseInt(param[i]);
        }

    }
}
