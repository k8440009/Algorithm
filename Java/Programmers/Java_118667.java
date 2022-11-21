import java.util.LinkedList;
import java.util.Queue;

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
/**
 * 1. Sum1 == Sum2
 * 2. sum이 홀수라면 -1 을 리턴
 * 3. S1 == S2가 될 때 까지 que1에서 que2로 이동 반대도 마찬가지
 * 4. S1 == S2인 경우 없으면 -1 리턴
 * 
 * 예제를 보고 그대로 구현하라는 내용이 있으면 그대로
 * 아닌 경우에는 어떻게 해야할지 생각해보고 구현 필요
 * 
 * @since 2022-09-21
 */
class Solution_118667 {
    public int solution(int[] queue1, int[] queue2) {
        long sum = 0;
        long sum1 = 0;
        long sum2 = 0;

        Queue <Integer> que1 = new LinkedList<>();
        Queue <Integer> que2 = new LinkedList<>(); 

        for (int num : queue1) {
            que1.add(num);
            sum1 += num;
        }

        for (int num : queue2) {
            que2.add(num);
            sum2 += num;
        }

        sum = sum1 + sum2;
        if (sum % 2 == 1) {
            return -1;
        } else {
            sum /= 2;

            int p1 = 0;
            int p2 = 0;
            int limit = queue1.length * 2;

            while(p1 <= limit && p2 <= limit) {
                if (sum1 == sum) return p1 + p2;

                if (sum1 > sum) {
                    sum1 -= que1.peek();
                    sum2 += que1.peek();
                    que2.add(que1.poll());
                    p1 += 1;
                } else {
                    sum2 -= que2.peek();
                    sum1 += que2.peek();
                    que1.add(que2.poll());
                    p2 += 1;
                }
            }
        }
        return -1;
    }
}