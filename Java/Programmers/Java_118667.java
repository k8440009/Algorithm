import java.util.ArrayList;

public class Java_118667 {
    public static void main(String[] args) {
        Solution_118667 test = new Solution_118667();

        System.out.println("test1");
        int [] queue11 = {3, 2, 7, 2};
        int [] queue12 = {4, 6, 5, 1};
        System.out.println(test.solution(queue11, queue12));

        // System.out.println("test2");
        // int [] queue21 = {1, 2, 1, 2};
        // int [] queue22 = {1, 10, 1, 2};
        // System.out.println(test.solution(queue21, queue22));

        // System.out.println("test3");
        // int [] queue31 = {1, 1};
        // int [] queue32 = {1, 5};
        // System.out.println(test.solution(queue31, queue32));
    }
}

class Solution_118667 {

    int minCnt = Integer.MAX_VALUE;
    public int solution(int[] queue1, int[] queue2) {
        int answer = -2;
        long sum1 = 0;
        long sum2 = 0;

        ArrayList<Integer> arr1 = new ArrayList<>();
        ArrayList<Integer> arr2 = new ArrayList<>();

        for (int num : queue1) {
            arr1.add(num);
            sum1 += num;
        }

        for (int num : queue2) {
            arr2.add(num);
            sum2 += num;
        }
        // 1. 계산 가능 여부 파악

        // 2. 큐 테스트
        dfs(sum1, sum2, 0, arr1, arr2);
        if (minCnt == Integer.MAX_VALUE) {
            answer = -1;
        } else {
            answer = minCnt;
        }
        return answer;
    }

    void dfs(long sum1, long sum2, int cnt, ArrayList<Integer> arr1,   ArrayList<Integer> arr2) {
        if (cnt == Integer.MAX_VALUE || cnt >= minCnt) {
            return ;
        }

        if (sum1 == sum2) {
            if (minCnt < cnt) {
                minCnt = cnt;
            }
            return;
        } else {
            ArrayList<Integer> nextArr1 = new ArrayList<>();
            ArrayList<Integer> nextArr2 = new ArrayList<>();

            for (int num : arr1) {
                nextArr1.add(num);
            }

            for (int num : arr2) {
                nextArr2.add(num);
            }

            if (nextArr1.size() != 0) {
                int top1 = nextArr1.get(0);
                nextArr1.remove(0);
                nextArr2.add(top1);
                dfs(sum1 - top1, sum2 + top1, cnt + 1, nextArr1, nextArr2);
                nextArr2.remove(nextArr2.size() - 1);
                nextArr1.add(top1);
            }

            if (nextArr2.size() != 0) {
                int top2 = nextArr2.get(0);
                nextArr2.remove(0);
                nextArr1.add(top2);
                dfs(sum1 + top2, sum2 - top2, cnt  + 1, nextArr1, nextArr2);
            }
        }
    }
}