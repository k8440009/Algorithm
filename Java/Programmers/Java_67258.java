import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Java_67258 {
    public static void main(String[] args) {
        Solution_67258 test = new Solution_67258();
        // String [] gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
        // String [] gems = {"AA", "AB", "AC", "AA", "AC"};
        // String [] gems = {"XYZ", "XYZ", "XYZ"};
        String [] gems = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};
        int [] answers = test.solution(gems);
        for (int answer : answers) {
            System.out.print(answer + " ");
        }
        System.out.println();
    }
}


class Solution_67258 {
    public int[] solution(String[] gems) {
        StringBuilder sb = new StringBuilder();
        Map <String, Integer> gemsMap = new HashMap<String, Integer>();
        Set <String> gemsSet = new HashSet<String>();

        for (String gem : gems) {
            gemsSet.add(gem);
        }

        int left = 0;
        int right = 0;

        int start = 0;
        int end = 0;
        while(true) {
            if (gemsSet.size() == gemsMap.size()) {
                left += 1;
            } else if (right == gems.length) {
                break;
            } else {
                String gem = gems[right];
                if (gemsMap.containsKey(gem)) {
                    gemsMap.put(gem, gemsMap.get(gem));
                } else {
                    gemsMap.put(gem, 0);
                }
                right += 1;
            }
        }
        int[] answer = new int[2];
        // answer[0] = start + 1;
        // answer[1] = end + 1;

        return answer;
    }
}