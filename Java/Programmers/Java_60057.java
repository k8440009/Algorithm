public class Java_60057 {
    public static void main(String[] args) {
        Solution_60057 test = new Solution_60057();
        // String s = "aabbaccc";
        String s = "ababcdcdababcdcd";
        int answer = test.solution(s);
        System.out.println("answer=" + answer);
    }
}

class Solution_60057 {
    public int solution(String s) {
        StringBuilder sb = new StringBuilder();
        int answer = s.length();

        for (int size = 1; size < s.length(); size++) {
            String before = "";
            String now = "";
            int cnt = 1;
            int endIndex = 0;
            sb.setLength(0);
            boolean flag = false;
            for (int i = 0; i < s.length(); i += size) {
                endIndex = i + size;

                if (endIndex > s.length()) {
                    endIndex = s.length();
                }
                now = s.substring(i, endIndex);
    
                // System.out.println("before=" + before + " now=" + now);
                
                if (flag != false) {
                    if (before.equals("") == false && before.equals(now)){
                        cnt += 1;
                    } else {
                        if (cnt != 1) {
                            sb.append(Integer.toString(cnt));
                        }
                        sb.append(before);
                        cnt = 1;
                    }
                }
                flag = true;
                before = now;
            }
            // 마지막
            if (cnt != 1) {
                sb.append(Integer.toString(cnt));
            }
            sb.append(before);
            // System.out.println("str=" + sb.toString() + " size=" + sb.toString().length());

            if (answer > sb.toString().length()) {
                answer = sb.toString().length();
            }
        }
        return answer;
    }
}