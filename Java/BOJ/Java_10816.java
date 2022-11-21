import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
/**
 * 자바 문자열 출력시
 * StringBuilder 사용 후 최종 출력하기 (시간초과방지)
 * 
 * @since 2022-09-09
 * @author SungSoo Lee
 */
public class Java_10816 {
    static ArrayList <Integer> numList = new ArrayList<>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int N = Integer.parseInt(br.readLine());
        String [] tokens = br.readLine().split(" ");
        for (String token : tokens) {
            numList.add(Integer.parseInt(token));
        }

        Collections.sort(numList);

        int M = Integer.parseInt(br.readLine());
        tokens = br.readLine().split(" ");
        for (String token : tokens) {
            sb.append(upperIndex(Integer.parseInt(token), numList.size()) 
                      - lowerIndex(Integer.parseInt(token),  numList.size())).append(" ");
        }
        System.out.println(sb.toString());
    }

    public static int lowerIndex(int target, int len) {
        int st = 0;
        int en = len;
        int mid = 0;

        while(st < en) {
            mid = (st + en) / 2;
            if (numList.get(mid) >= target) {
                en = mid;
            } else {
                st = mid + 1;
            }
        }
        return st;
    }

    public static int upperIndex(int target, int len) {
        int st = 0;
        int en = len;
        int mid = 0;

        while(st < en) {
            mid = (st + en) / 2;
            if (numList.get(mid) > target) {
                en = mid;
            } else {
                st = mid + 1;
            }
        }
        return st;
    }

}