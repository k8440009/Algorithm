import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Java_2309 {
    static ArrayList <Integer> arrayList = new ArrayList<>();
    static boolean flag = false;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 9; i++){
            arrayList.add(i, Integer.parseInt(br.readLine()));
        }
        
        int cnt = 0;
        int sum = 0;
        ArrayList <Integer> numbers = new ArrayList<>();
        for (int i = 0; i < 9; i++){
            int start = arrayList.get(i);
            numbers.add(start);
            dfs(i, cnt + 1, sum + arrayList.get(i), numbers);
            numbers.clear();
        }
    }

    public static void dfs (int idx, int cnt, int sum, ArrayList<Integer> numbers) {
        if (sum > 100 || flag == true){
            return ;
        }

        if (cnt == 7){
            if (sum == 100){
                Collections.sort(numbers);
                flag = true;
                for (int i = 0; i < 7; i++){
                    System.out.println(numbers.get(i));
                }
            }
            return ;
        }

        for (int i = idx + 1; i < 9; i++){
            numbers.add(arrayList.get(i));
            dfs(i, cnt + 1, sum + arrayList.get(i), numbers);
            numbers.remove(numbers.size() - 1);
        }
    }
}