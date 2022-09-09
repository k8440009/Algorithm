import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Java_10816 {
    static ArrayList <Integer> numList = new ArrayList<>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String [] tokens = br.readLine().split(" ");
        for (String token : tokens) {
            numList.add(Integer.parseInt(token));
        }

        Collections.sort(numList);

        int M = Integer.parseInt(br.readLine());
        tokens = br.readLine().split(" ");
        for (String token : tokens) {
            System.out.print(upperIndex(Integer.parseInt(token), numList.size()) - lowerIndex(Integer.parseInt(token),  numList.size()) + " ");
        }
        System.out.println();
    }

    public static int lowerIndex(int target, int len) { // C++ lower_bound
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

    public static int upperIndex(int target, int len) { // C++ upper_bound
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
