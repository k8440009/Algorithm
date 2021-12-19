import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        ArrayList<Integer> numbers = new ArrayList<>();
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++){
            numbers.add(Integer.parseInt(st.nextToken()));
        }

        int max = numbers.get(0);
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += numbers.get(i);
            max = Math.max(max, sum);
            if (sum < 0)
                sum = 0;
        }
        System.out.print(max);
	}
}