import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Java_42888 {
    public static void main(String[] args) {
        Solution_42888 test = new Solution_42888();

        String [] records = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
        String [] answers = test.solution(records);
        for (String answer : answers) {
            System.out.println("answer=" + answer);
        }
    }
}

class Solution_42888 {
    public String[] solution(String[] records) {
        StringBuilder sb = new StringBuilder();
        Map <String, String> userMap = new HashMap<String, String>();
        ArrayList <String> commandArr = new ArrayList<String>();
        for (String record : records) {
            String [] tokens = record.split(" ");

            String command = tokens[0];
            String uid = tokens[1];
            String nickname = "";

            if (tokens.length == 3){
                nickname = tokens[2];
                userMap.put(uid, nickname);
            }

            if ("Change".equals(command) == false) {
                sb.setLength(0);
                sb.append(command).append(" ").append(uid);
                commandArr.add(sb.toString());
            }
        }

        String [] answer = new String [commandArr.size()];
        int index = 0;
        for (String str : commandArr) {
            String [] tokens = str.split(" ");

            String command = tokens[0];
            String uid = tokens[1];
            String nickname = userMap.get(uid);

            sb.setLength(0);
            if ("Enter".equals(command)) {
                sb.append(nickname).append("님이 들어왔습니다.");
            } else if ("Leave".equals(command)) {
                sb.append(nickname).append("님이 나갔습니다.");
            }
            answer[index] = sb.toString();
            index += 1;
        }
        return answer;
    }
}