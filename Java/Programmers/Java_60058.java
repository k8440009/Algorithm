import java.util.ArrayList;
import java.util.Stack;

public class Java_60058 {
    public static void main(String[] args) {
        Solution_60058 test = new Solution_60058();

        System.out.println("test");
        System.out.println(test.solution("()"));

        System.out.println("test1");
        System.out.println(test.solution("(()())()"));

        System.out.println("test2");
        System.out.println(test.solution(")("));

        System.out.println("test3");
        System.out.println(test.solution("()))((()"));
    }
}

class Solution_60058 {
    public String solution(String p) {
        String answer = "";
        answer = dfs(p);
        return answer;
    }

    String dfs(String w) {
        if ("".equals(w) == true) {
            return w;
        }

        StringBuilder sb = new StringBuilder();
        ArrayList <String> strings = divString(w);

        String u = strings.get(0);
        String v = strings.get(1);

        // System.out.println("w=" + w);
        // System.out.println("u=" + u + " correct=" + correctString(u));
        // System.out.println("v=" + v + " correct=" + correctString(v));

        if (correctString(u) == true) {
            sb.setLength(0);

            sb.append(u);
            String newStr = dfs(v);
            if ("".equals(newStr) == false) {
                sb.append(newStr);
            }
        } else {
            // 빈 문자열
            sb.setLength(0);

            sb.append("(");
            String newStr = dfs(v);
            sb.append(newStr);
            sb.append(")");

            for (int i = 1; i < u.length() - 1; i++) {
                if (u.charAt(i) == '(') {
                    sb.append(")");
                } else {
                    sb.append("(");
                }
            }
        }
        return sb.toString();
    }

    boolean correctString(String str) {
        Stack<String> stack = new Stack<>();
        boolean chk = true;
        /**
         * '(' 경우 push
         */
        for (int i = 0; i < str.length(); i++) {
            String ch = Character.toString(str.charAt(i));

            if ("(".equals(ch)) {
                stack.push(ch);
            } else {
                if (stack.isEmpty()) {
                    chk = false;
                    break;
                } else {
                    stack.pop();
                }
            }
        }
        return chk;
    }


    ArrayList<String> divString (String str) {
        ArrayList<String> sList = new ArrayList<>();

        int left = 0;
        int right = 0;
        int cnt = 0;
        for (int i = 0; i < str.length(); i++) {
            cnt += 1;
            if (str.charAt(i) == '(') {
                left += 1;
            } else {
                right += 1;
            }

            if (left != 0 && right != 0) {
                if (left == right) {
                    break;
                }
            }
        }

        String u = str.substring(0, cnt);
        String v = "";
        if (str.length() != cnt) {
            v = str.substring(cnt, str.length());
        }

        sList.add(u);
        sList.add(v);

        return sList;
    }
}
