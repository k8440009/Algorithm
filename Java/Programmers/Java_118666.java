import java.util.HashMap;
import java.util.Map;

public class Java_118666 {
    public static void main(String[] args) {
        Solution_118666 test = new Solution_118666();
        System.out.println("test1");
        String [] survey1 =  {"AN", "CF", "MJ", "RT", "NA"};
        int [] choices1 =  {5, 3, 2, 7, 5};
        System.out.println(test.solution(survey1, choices1));

        System.out.println("test2");
        String [] survey2 =  {"TR", "RT", "TR"};
        int [] choices2 =  {7, 1, 3};
        System.out.println(test.solution(survey2, choices2));

    }
}

class Solution_118666{
    public String solution(String[] surveys, int[] choices) {
        String answer = "";

        Map <String, Integer> aMap = new HashMap<>();
        // 1
        aMap.put("R", 0);
        aMap.put("T", 0);
        // 2
        aMap.put("C", 0);
        aMap.put("F", 0);
        // 3
        aMap.put("J", 0);
        aMap.put("M", 0);
        // 4
        aMap.put("A", 0);
        aMap.put("N", 0);

        int index = -1;
        for (int choice : choices) {
            index += 1;
            String [] tokens = surveys[index].split("");

            String first = tokens[0];
            String second = tokens[1];

            switch(choice) {
                case 1:
                aMap.put(first, aMap.get(first) + 3);
                break;
                case 2:
                aMap.put(first, aMap.get(first) + 2);
                break;
                case 3:
                aMap.put(first, aMap.get(first) + 1);
                break;
                case 4:
                break;
                case 5:
                aMap.put(second, aMap.get(second) + 1);
                break;
                case 6:
                aMap.put(second, aMap.get(second) + 2);
                break;
                case 7:
                aMap.put(second, aMap.get(second) + 3);
                break;
            }
        }

        // for (Map.Entry<String, Integer> entry : aMap.entrySet()) {
        //     System.out.println("key=" + entry.getKey() + " value=" + entry.getValue());
        // }

        StringBuilder sb = new StringBuilder();

        if (aMap.get("R") > aMap.get("T")) {
            sb.append("R");
        } else if (aMap.get("R") < aMap.get("T")) {
            sb.append("T");
        } else {
            sb.append("R");
        }

        if (aMap.get("C") > aMap.get("F")) {
            sb.append("C");
        } else if (aMap.get("C") < aMap.get("F")) {
            sb.append("F");
        } else {
            sb.append("C");
        }

        if (aMap.get("J") > aMap.get("M")) {
            sb.append("J");
        } else if (aMap.get("J") < aMap.get("M")) {
            sb.append("M");
        } else {
            sb.append("J");
        }

        if (aMap.get("A") > aMap.get("N")) {
            sb.append("A");
        } else if (aMap.get("A") < aMap.get("N")) {
            sb.append("N");
        } else {
            sb.append("A");
        }

        return sb.toString();
    }
}