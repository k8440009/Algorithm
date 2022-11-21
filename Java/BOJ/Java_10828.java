import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;
import java.util.StringTokenizer;

public class Java_10828 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Stack<Integer> stack = new Stack<>();

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String str  = br.readLine();
            String split[] = str.split(" ");

            String command = split[0];
            if ("push".equals(command)){
                String num = split[1];
                
            } else if ("pop".equals(command)){

            } else if ("size".equals(command)){

            } else if ("empty".equals(command)){

            } else if ("top".equals(command)){

            }

        }
    }
}