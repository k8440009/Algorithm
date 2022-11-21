import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

/**
 * 정렬하여 중복 제거 후 이분 탐색
 * 
 * @since 2022-09-09
 * @author SungSoo Lee
 */
public class Java_18870 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        ArrayList <Integer> arrayList = new ArrayList<>();
        ArrayList <Integer> sortList = new ArrayList<>();
        ArrayList <Integer> numList = new ArrayList<>();
        int N = Integer.parseInt(br.readLine());
        String [] tokens = br.readLine().split(" ");

        for (String token : tokens) {
            arrayList.add(Integer.parseInt(token));
            sortList.add(Integer.parseInt(token));
        }

        Collections.sort(sortList);        
        // 중복제거
        int basis = sortList.get(0);
        numList.add(basis);
        for (int num : sortList) {
            if (basis != num) {
                numList.add(num);
                basis = num;
            }
        }

        for (int num : arrayList) {
            sb.append(binarySearch(numList, num)).append(" ");
        }
        System.out.println(sb.toString());
    }

    public static int binarySearch(ArrayList<Integer> arrayList, int target) {
        int st = 0;
        int en = arrayList.size() - 1;
        int mid = -1;

        while(st <= en) {
            mid = (st + en) / 2;

            if (arrayList.get(mid) < target) {
                st = mid + 1;
            } else if (arrayList.get(mid) > target){
                en = mid - 1;
            } else {
                break;
            }
        }
        return mid;
    }
}
