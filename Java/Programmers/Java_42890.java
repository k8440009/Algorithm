import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Java_42890 {
    public static void main(String[] args) {
        Solution_42890 test = new Solution_42890();
        String [][] relation1 = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},
        {"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
        System.out.println(test.solution(relation1));
    }
}

class Solution_42890 {
    static int maxCol;
    static int maxKeyCnt;
    static Map <String, Integer> keyMap = new HashMap<>();
    public int solution(String[][] relation) {
        int answer = 0;
        // System.out.println("row=" + relation.length + " col=" + relation[0].length);

        maxCol = relation[0].length;

        for (int cnt = 1; cnt <= maxCol; cnt++) {
            boolean [] visited = new boolean [maxCol];
            dfs(0, 0, cnt, visited, relation);
        }

        answer = maxKeyCnt;
        return answer;
    }
    boolean checkRelationKey(boolean [] visited, String [][] relations) {
        Map <String, Integer> aMap = new HashMap<>();
        ArrayList <Integer> arrayList = new ArrayList<>();
        for (int i = 0; i < visited.length; i++) {
            if (visited[i] == true) {
                arrayList.add(i);
            }
        }
        // 유일성 체크
        StringBuilder sb = new StringBuilder();
        for (String [] relation : relations) {
            sb.setLength(0);

            for (int index : arrayList) {
                String str = relation[index].replace("\"", "");
                sb.append(str);
            }

            String key = sb.toString();
            if (aMap.containsKey(key)) {
                return false;
            } else {
                aMap.put(key, 1);
            }
        }
        // 최소성 체크
        sb.setLength(0);
        for (int i = 0; i < visited.length; i++) {
            if (visited[i])
                sb.append(Integer.toString(i));
        }

        String key = sb.toString();
        String [] keyTokens = key.split("");
        for (Map.Entry<String, Integer> entry : keyMap.entrySet()) {
            String [] keyStrings = entry.getKey().split("");

            int cnt = 0;
            for (String keyString : keyStrings) {
                for (String keyToken : keyTokens) {
                    if (keyString.equals(keyToken) == true) {
                        cnt += 1;
                    }
                }

                if (cnt == entry.getKey().length()) {
                    return false;
                }
            }
        }

        keyMap.put(key, 1);
        return true;
    }
    void dfs(int index, int cnt, int selectedCnt, boolean [] visited, String [][] relation) {
        if (cnt == selectedCnt) {
            if (checkRelationKey(visited, relation) == true) {
                maxKeyCnt += 1;
            }
            return ;
        }

        for (int i = index; i < maxCol; i++) {
            if (visited[i] == true)
                continue;

            visited[i] = true;
            dfs(i, cnt + 1, selectedCnt, visited, relation);
            visited[i] = false;
        }
    }
}