package Algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

/**
 * 경우의 수 (NumberOfCases)
 * 순열, 조합, 중복순열, 중복조합 정리
 * 
 * nPr
 * nCr
 * 중복순열 n ^ r
 * nHr = (n + r - 1)C r
 * 
 * ex) n = 4, r = 3
 * nPr : 24 
 * nCr : 4
 * 중복순열 n ^ r : 64
 * nHr = (n + r - 1)C r = 20
 * 
 * n개중에서 r개를 선택 할 때를 기준으로 처리한다.
 * 
 * 순열과, 조합은 visited 배열을 사용하여, 중복을 체크한다.
 * 조합은 Index를 사용하여, 이전 데이터를 사용하지 않는다.
 * 
 * [참조]
 * https://limkydev.tistory.com/178
 * https://ourcalc.com/%EC%88%9C%EC%97%B4-%EA%B3%84%EC%82%B0%EA%B8%B0/
 * https://ourcalc.com/%EC%A1%B0%ED%95%A9-%EA%B3%84%EC%82%B0%EA%B8%B0/
 * 
 * @author SungSooLee
 * @since 2022-08-03
 */
public class NumberOfCases {
    static int N;
    static int R;
    static int totalCnt = 0;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        LinkedList <Integer> arr = new LinkedList<Integer>();

        String [] tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        R = Integer.parseInt(tokens[1]);

        boolean [] visited = new boolean [N];

        
        // 순열
        // permutation
        System.out.println("===== permutation =====");
        totalCnt = 0;
        permutation(0, R, arr, visited);
        System.out.println("totalCnt=" + totalCnt);
        // 조합
        // combination
        System.out.println("===== combination =====");
        totalCnt = 0;
        combination(0, 0, R, arr, visited);
        System.out.println("totalCnt=" + totalCnt);
        // 중복순열
        // rePermutation
        System.out.println("===== rePermutation =====");
        totalCnt = 0;
        rePermutation(0, R, arr);
        System.out.println("totalCnt=" + totalCnt);
        // 중복 조합
        // reCombination
        System.out.println("===== reCombination =====");
        totalCnt = 0;
        reCombination(0, 0, R, arr);
        System.out.println("totalCnt=" + totalCnt);
    }

    private static void permutation (int cnt, int r, LinkedList<Integer> arr, boolean [] visited) {
        if (cnt == R) {
            totalCnt += 1;
            for (int i : arr) {
                System.out.print(i + " ");
            }
            System.out.println();
            return ;
        }

        for (int i = 0; i < N; i++) {
            if (visited[i] == false) {
                arr.add(i);
                visited[i] = true;
                permutation(cnt + 1, r, arr, visited);
                visited[i] = false;
                arr.removeLast();
            }
        }
    }

    private static void rePermutation (int cnt, int r,  LinkedList<Integer> arr) {
        if (cnt == R) {
            totalCnt += 1;
            for (int i : arr) {
                System.out.print(i + " ");
            }
            System.out.println();
            return ;
        }

        for (int i = 0; i < N; i++) {
            arr.add(i);
            rePermutation(cnt + 1, r, arr);
            arr.removeLast();
        }
    }

    private static void combination (int index, int cnt, int r, LinkedList<Integer> arr, boolean [] visited) {
        if (cnt == R) {
            totalCnt += 1;
            for (int i : arr) {
                System.out.print(i + " ");
            }
            System.out.println();
            return ;
        }

        for (int i = index; i < N; i++) {
            if (visited[i] == false) {
                arr.add(i);
                visited[i] = true;
                combination(i, cnt + 1, r, arr, visited);
                visited[i] = false;
                arr.removeLast();
            }
        }
    }

    private static void reCombination (int index, int cnt, int r,  LinkedList<Integer> arr) {
        if (cnt == R) {
            totalCnt += 1;
            for (int i : arr) {
                System.out.print(i + " ");
            }
            System.out.println();
            return ;
        }

        for (int i = index; i < N; i++) {
            arr.add(i);
            reCombination(i, cnt + 1, r, arr);
            arr.removeLast();
        }
    }
}
