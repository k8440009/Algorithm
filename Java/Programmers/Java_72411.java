import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Java_72411 {
    public static void main(String[] args) {
        String [] orders ={
            "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"
        };
        int [] course = {
            2, 3, 4
        };

        Solution_72411 test = new Solution_72411();
        String [] answers = test.solution(orders, course);
        for (String answer : answers) {
            System.out.print(answer + " ");
        }
        System.out.println();

    }
}

class Solution_72411{
    Map <String, Integer> map = null;
    Map <Integer, String> maxData = null;
    public String[] solution(String[] orders, int[] courses) {
        int [] maxCourse = new int [11];
        map = new HashMap<String, Integer>();
        maxData = new HashMap<Integer, String>();
        for (String order : orders) {
            String [] tokens = order.split("");
            int n = tokens.length;
            boolean [] visited = new boolean[n];

            Arrays.sort(tokens);
            for (int course : courses) {
                combination(tokens, visited, 0, n, course); 
            }
        }


        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            String key = entry.getKey();
            int value = entry.getValue();

            int maxCnt = maxCourse[key.length()];

            if (maxCnt == 0) {
                if (value > 1) {
                    maxCourse[key.length()] = value;
                    maxData.put(key.length(), key);
                }
            } else {
                if (value > maxCnt) {
                    maxCourse[key.length()] = value;
                    maxData.put(key.length(), key);
                } else if (value == maxCnt) {
                    maxData.put(key.length(), maxData.get(key.length()).concat(" ").concat(key));
                }
            }
        }

        ArrayList <String> menuSets = new ArrayList<>();
        for (Map.Entry<Integer, String> entry : maxData.entrySet()) {
            String [] tokens = entry.getValue().split(" ");

            for (String token : tokens) {
                if (token.equals("") == false) {
                    menuSets.add(token);
                }
            }
        }

        Collections.sort(menuSets);

        //     if (maxData.containsKey(value)) {
        //         maxData
        //     } else {

        //     }
        // }
            
        String[] answer = new String[menuSets.size()];
        int i = 0;
        for (String menu : menuSets) {
            answer[i] = menu;
            i += 1;
        }
        return answer;
    }

    private void combination (String [] arr, boolean [] visited, int start, int n, int r) {
        if (r == 0) {
            StringBuilder sb = new StringBuilder();
            String str = null;
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    sb.append(arr[i]);
                }
            }

            str = sb.toString();
            if (map.containsKey(str) == true) {
                map.put(str, map.get(str) + 1);
            } else {
                map.put(str, 1);
            }
            return ;
        }

        for (int i = start; i < n; i++) {
            visited[i] = true;
            combination(arr, visited, i + 1, n, r - 1);
            visited[i] = false;
        }
    }
}