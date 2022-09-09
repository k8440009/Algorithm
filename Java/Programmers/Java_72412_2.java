import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

/**
 * 해시 + 이분탐색
 * 1. HashMap으로 쿼리 데이터 그룹화
 * 2. 이분탐색으로 점수 효율성 체크
 * 
 * @since 2022-09-09
 * @author SungSoo Lee
 */
public class Java_72412_2 {
    public static void main(String[] args) {

        Solution_72412_2 test = new Solution_72412_2();
        String [] infos = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
        String [] querys = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
        int [] answers = test.solution(infos, querys);
        for (int i = 0; i < answers.length; i++) {
            System.out.print(answers[i] + " ");
        }
        System.out.println();
    }
}
// 점수순으로 정렬
class People_72412_2 implements Comparable<People_72412_2>{
    String lang;
    String job;
    String year;
    String food;
    int  score;

    People_72412_2(String lang, String job, String year, String food, int score) {
        this.lang = lang;
        this.job = job;
        this.year = year;
        this.food = food;
        this.score = score;
    }

    @Override
    public int compareTo(People_72412_2 o) {
        return this.score - o.score;
    }
}

class Solution_72412_2{
    static Map<String, ArrayList<Integer>> aMap;
    static ArrayList <Integer> scoreArrayList;
    public int[] solution(String[] infos, String[] querys) {
        StringBuilder sb = new StringBuilder();

        int[] answer = new int [querys.length];
        aMap = new HashMap<>();
        int answerIndex = 0;
        // 해시 생성
        for (String info : infos) {
            String [] tokens = info.split(" ");

            String key = tokens[0];
            dfs(1, key, tokens);
            key = "-";
            dfs(1, key, tokens);
        }
        // 정렬
        for (Map.Entry<String, ArrayList<Integer>> entry : aMap.entrySet()) {
            Collections.sort(entry.getValue());
        }
        
        for (String query : querys) {
            String [] tokens = query.split("and");
            
            String lang = tokens[0].trim();
            String job = tokens[1].trim();
            String year = tokens[2].trim();

            String [] splitStr = tokens[3].trim().split(" ");
            String food = splitStr[0].trim();
            int target = Integer.parseInt(splitStr[1].trim());

            sb.setLength(0);

            String key = sb.append(lang).append(job).append(year).append(food).toString();

            scoreArrayList = aMap.get(key);

            int cnt = 0;
            if (scoreArrayList != null) { // 잘못된 쿼리 입력 되는 경우 pass
                cnt =  scoreArrayList.size() - lowerIndex(target, scoreArrayList.size());
            }
            answer[answerIndex] = cnt;
            answerIndex += 1;
        }
        return answer;
    }

    static void dfs(int index, String key, String [] tokens) {
        if (index == 4) {
            ArrayList <Integer> arr = new ArrayList<>();
            if (aMap.containsKey(key)) {
                arr = aMap.get(key);
            }
            arr.add(Integer.parseInt(tokens[4]));

            aMap.put(key, arr);

            return ;
        }
        String key1 = key;
        String key2 = key;

        key1 = key1.concat(tokens[index]);
        dfs(index + 1, key1, tokens);

        key2 = key2.concat("-");
        dfs(index + 1, key2, tokens);
    }

    static int lowerIndex(int target, int len) { // C++ lower_bound
        int st = 0;
        int en = len;
        int mid = 0;

        while(st < en) {
            mid = (st + en) / 2;
            if (scoreArrayList.get(mid) >= target) {
                en = mid;
            } else {
                st = mid + 1;
            }
        }
        return st;
    }
}