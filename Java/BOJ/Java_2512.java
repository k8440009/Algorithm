import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_2512 {
    static int N, M;
    static int [] money;
    static long K;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] param = br.readLine().split(" ");
        String [] tokens = br.readLine().split(" ");
        String [] answer = br.readLine().split(" ");


        long checkSum = 0;
        long maxMoney = 0;

        N = Integer.parseInt(param[0]);
        money = new int [N];
        for (int i = 0; i < N; i++){
            money[i] =  Integer.parseInt(tokens[i]);
            
            checkSum += money[i];
            if (money[i] > maxMoney){
                maxMoney = money[i];
            }
        }
        K = Long.parseLong(answer[0]);


        if (K >= checkSum){
            System.out.println(maxMoney);
        } else {
            long lo = 0;
            long hi = 1000000000;
            while(lo + 1 < hi){
                long mid = (lo + hi) / 2;
                
                long sum = 0;
                for (int i = 0; i < N; i++){
                    if (money[i] > mid){
                        sum += mid;
                    } else{
                        sum += money[i];
                    }
                }
    
                if (sum > K){
                    hi = mid;
                } else{
                    lo = mid;
                }
            }
            System.out.println(lo);
        }
    }
}
