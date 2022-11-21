import java.util.HashMap;
import java.util.Map;
import java.util.regex.Pattern;

public class Java_17677 {
    public static void main(String[] args) {
        Solution_17677 test = new Solution_17677();

        System.out.println("test1");
        System.out.println(test.solution("FRANCE", "french"));

        System.out.println("test2");
        System.out.println(test.solution("handshake", "shake hands"));

        System.out.println("test3");
        System.out.println(test.solution("aa1+aa2", "AAAA12"));

        System.out.println("test4");
        System.out.println(test.solution("E=M*C^2", "e=m*c^2"));
    }
}
/**
 * 1. 전처리
 * 1) 영어 대문자 처리
 * 2) 정규식을 사용하여 제거
 * 3) a 그룹과 b 그룹을 해시로 저장한다. 
 * - 중복 된 데이터는 + 1 해준다.
 * 
 * 2. 합 집합
 * 1) 새로운 해시 c에 a를 넣는다.
 * 2) 새로운 해시 c에 b를 넣으면서 중복되면 max를 넣는다.
 * 3) c를 entry로 방문하면서 데이터 갯수를 가져온다.
 * 
 * 3. 교 집합
 * 1) a, b를 이중 포운을 사용하여 체크한다.
 * - 중복된 것이 있을 경우 min을 체크하고 diff에 더한다.
 * 2) diff를 리턴한다.
 * 
 * 4. 계산시
 * 1) a,b 모두 공백 => 1
 * 2) a 또는 b 가 공백 => 0
 * 3) 나머지 경우 연산
 */
class Solution_17677 {
    static Map<String, Integer> aMap;
    static Map<String, Integer> bMap;
    public int solution(String str1, String str2) {
        int answer = 0;
        aMap = new HashMap<>();
        bMap = new HashMap<>();

        str1 = str1.toUpperCase();
        str2 = str2.toUpperCase();

        String regex = "^[A-Z]*$";

        for (int i = 0; i < str1.length() - 1; i++) {
            String subString = str1.substring(i, i + 2);
            if (Pattern.matches(regex, subString)) {
                if (aMap.containsKey(subString)) { // hit
                    aMap.put(subString, aMap.get(subString) + 1);
                } else { // miss
                    aMap.put(subString, 1);
                }
            }
        }

        for (int i = 0; i < str2.length() - 1; i++) {
            String subString = str2.substring(i, i + 2);

            if (Pattern.matches(regex, subString)) {
                if (bMap.containsKey(subString)) { // hit
                    bMap.put(subString, bMap.get(subString) + 1);
                } else { // miss
                    bMap.put(subString, 1);
                }
            }
        }

        double tmp = 0;
        if (aMap.size() == 0 && bMap.size() == 0) {
            tmp = 1;
        } else if (aMap.size() == 0 || bMap.size() == 0) {
            tmp = 0;
        } else {
            int sum = sumSet();
            int dif = diffSet();

            tmp = (double)dif / (double)sum;
        }
        answer = (int)(tmp * 65536);
        return answer;
    }

    // 합집합
    static int sumSet() {
        int sum = 0;

        Map<String, Integer> cMap = new HashMap<>();
        for (Map.Entry<String, Integer> entry : aMap.entrySet()) {
            cMap.put(entry.getKey(), entry.getValue());
        }

        for (Map.Entry<String, Integer> entry : bMap.entrySet()) {
            String key = entry.getKey();
            if (cMap.containsKey(key)) { // hit
                int maxData = Math.max(cMap.get(key), bMap.get(key));
                cMap.put(key, maxData);
            } else { // miss
                cMap.put(key, entry.getValue());
            }
        }

        for (Map.Entry<String, Integer> entry : cMap.entrySet()) {
            int value = entry.getValue();
            sum += value;
        }

        return sum;
    }

    // 교집합
    static int diffSet() {
        int diff = 0;
        for (Map.Entry<String, Integer> aEntry : aMap.entrySet()) {
            for (Map.Entry<String, Integer> bEntry : bMap.entrySet()) {
                String aKey = aEntry.getKey();
                String bKey = bEntry.getKey();

                if (aKey.equals(bKey)) {
                    int minData = Math.min(aMap.get(aKey), bMap.get(bKey));
                    diff += minData;
                }
            }
        }
        return diff;
    }
}