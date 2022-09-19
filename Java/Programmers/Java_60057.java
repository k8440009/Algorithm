public class Java_60057 {
    public static void main(String[] args) {
        Solution_60057 test = new Solution_60057();
        
        System.out.println("test1");
        System.out.println(test.solution("aabbaccc"));

        System.out.println("test2");
        System.out.println(test.solution("ababcdcdababcdcd"));

        System.out.println("test3");
        System.out.println(test.solution("abcabcdede"));

        System.out.println("test4");
        System.out.println(test.solution("abcabcabcabcdededededede"));

        System.out.println("test5");
        System.out.println(test.solution("xababcdcdababcdcd"));
    }
}

class Solution_60057 {
    public int solution(String s) {
        int answer = Integer.MAX_VALUE;
        StringBuilder sb = new StringBuilder();
        for (int cnt = 1; cnt <= s.length(); cnt++) {
            String bf = s.substring(0, cnt);

            sb.setLength(0);
            int beginIndex = cnt;
            int same = 1;
            while(true) {
                int endIndex = -1;
                boolean flag = false;
                /**
                 * 인덱스처리
                 * beginIndex, endIndex
                 * 
                 * beginIndex
                 * endIndex = beginIndex + cnt
                 * 
                 * 
                 */
                 endIndex = beginIndex + cnt;
                 if (endIndex >= s.length()) {
                    endIndex = s.length();
                    flag = true;
                 }
                String subString = s.substring(beginIndex, endIndex);
                /**
                 * 1. 같은 경우
                 * - same += 1
                 * 2. 다른 경우
                 * - sb에 넣음
                 * - 이전 데이터 덮어 씌움
                 */
                if (bf.equals(subString) == true) {
                    same += 1;
                } else {
                    if (same != 1) {
                        sb.append(Integer.toString(same));
                    }
                    sb.append(bf);
                    same = 1;
                    bf = subString;
                }

                if (flag) {
                    if (same == 1) {
                        sb.append(bf);
                    } else {
                        sb.append(Integer.toString(same)).append(bf);
                    }
                    break;
                } else {
                     beginIndex = endIndex;
                }
            }
            answer = Math.min(sb.toString().length(), answer);
        }

        return answer;
    }
}