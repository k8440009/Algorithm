import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Java_17678 {
    public static void main(String[] args) {
        Solution_17678 test = new Solution_17678();
        String answer = "";

        System.out.println("test1");
        String [] timetable1 = {"08:00", "08:01", "08:02", "08:03"};
        answer = test.solution(1, 1, 5, timetable1);
        System.out.println(answer);

        System.out.println("test2");
        String [] timetable2 = 	{"09:10", "09:09", "08:00"};
        answer = test.solution(2, 10, 2, timetable2);
        System.out.println(answer);

        System.out.println("test3");
        String [] timetable3 = 	{"09:00", "09:00", "09:00", "09:00"};
        answer = test.solution(2, 1, 2, timetable3);
        System.out.println(answer);

        System.out.println("test4");
        String [] timetable4 = 	{"00:01", "00:01", "00:01", "00:01", "00:01"};
        answer = test.solution(1, 1, 5, timetable4);
        System.out.println(answer);

        System.out.println("test5");
        String [] timetable5 = 	{"23:59"};
        answer = test.solution(1, 1, 1, timetable5);
        System.out.println(answer);

        System.out.println("test6");
        String [] timetable6 = {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"};
        answer = test.solution(10, 60, 45, timetable6);
        System.out.println(answer);
    }
}

class Solution_17678 {
    /*
     * 버스 시작시간 09:00
     * n : 횟수 1 ~ 10
     * t : 운행 간격 1 ~ 60 (최대 10시간)
     * m : 최대 탈 수 있는 크루수 1 ~ 45
     *
     * 시뮬레이션
     * 0. timeTable을 정렬 한 후, 큐에 넣는다. (대기열 구현)
     * 1. 버스 시간을 계산한다.
     * 2. 버스에 사람을 태운다.
     * 1) 기저
     * - 정원이 가득 찬 경우
     * - 대기열이 비어 있는 경우
     * 
     * 2) 큐 연산
     * - 큐 시간과 버스 시간을 비교하였을 때, 버스 시간 보다 작거나 같은 경우 큐에서 제거한다. 
     *   그리고 그 시간을 기록해둔다. cnt를 증가시킨다.
     * 
     * 3) 후 처리
     * 3-1) cnt가 버스 정원과 같은 경우
     * - 마지막 승객 시간의 -1 분을 한다.
     * 3-2) 작은 경우
     * - 버스 도착시간이 가장 뒤 늦은 시간
     * 
     */
    public String solution(int n, int t, int m, String[] timetable) {
        String answer = "";
        String busTime = "09:00";

        Arrays.sort(timetable);

        Queue <String> queue = new LinkedList<>();
        for (String time : timetable) {
            queue.add(time);
        }

        for (int bus = 0; bus < n; bus++) {
            int cnt = 0;
            String lastTime = "";

            if (bus != 0) {
                busTime = calTime(busTime, t);
            }

            while(!queue.isEmpty()) {
                String cur = queue.peek();
                if (cnt == m || (cur.compareTo(busTime) > 0)) {
                    break;
                }

                if (cur.compareTo(busTime) <= 0) {
                    lastTime = queue.poll();
                    cnt += 1;
                }
            }

            if (cnt == m) {
                answer = diffMinuteTime(lastTime);
            } else {
                answer = busTime;
            }
        }
        return answer;
    }
    static String diffMinuteTime (String now) {
        StringBuilder sb = new StringBuilder();
        String [] tokens = now.split(":");

        int h = Integer.parseInt(tokens[0]);
        int m = Integer.parseInt(tokens[1]);

        if (m - 1 >= 0) {
            m -= 1;
        } else {
            h -= 1;
            m += 59;
        }

        sb.setLength(0);
        if (h < 10) {
            sb.append("0");
        }
        sb.append(Integer.toString(h)).append(":");

        if (m < 10) {
            sb.append("0");
        }
        sb.append(Integer.toString(m));

        return sb.toString();
    }
    static String calTime(String now, int t) {
        StringBuilder sb = new StringBuilder();
        String [] tokens = now.split(":");

        int h = Integer.parseInt(tokens[0]);
        int m = Integer.parseInt(tokens[1]);

        m += t;
        if (m >= 60) {
            h += (m / 60);
            m %= 60;
        }

        sb.setLength(0);
        if (h < 10) {
            sb.append("0");
        }
        sb.append(Integer.toString(h)).append(":");

        if (m < 10) {
            sb.append("0");
        }
        sb.append(Integer.toString(m));

        return sb.toString();
    }
}