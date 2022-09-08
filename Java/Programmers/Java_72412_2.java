import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

/**
 * 효율성 푸는중..
 * 
 * 해시 + 이분탐색
 * @since 2022-09-08
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
    public int[] solution(String[] infos, String[] querys) {
        StringBuilder sb = new StringBuilder();

        //ArrayList <People_72412_2> arrayList = new ArrayList<>();
        int[] answer = new int [querys.length];
        aMap = new HashMap<>();
        int answerIndex = 0;

        for (String info : infos) {
            String [] tokens = info.split(" ");

            //arrayList.add(new People_72412_2(tokens[0], tokens[1], tokens[2], tokens[3], Integer.parseInt(tokens[4])));

           // System.out.println("mod0");
            String key = tokens[0];
            dfs(1, key, tokens);
            //System.out.println("mod1");
            key = "-";
            dfs(1, key, tokens);
        }

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
            //System.out.println("key=" + key + " target=" + target);

            ArrayList <Integer> scoreArrayList;
            scoreArrayList = aMap.get(key);
            
            int lo = 0;
            int hi = scoreArrayList.size() - 1;
            int mid = -1;
            boolean findTarget = false;
            while(lo <= hi) {
                mid = (lo + hi)  / 2;

                if (scoreArrayList.get(mid) < target) {
                    lo = mid + 1;
                } else if (scoreArrayList.get(mid) > target) {
                    hi = mid - 1;
                } else {
                    lo = mid; // 만족하는 최소값
                    findTarget = true;
                    break;
                }
            }
            
            // if ()
            answer[answerIndex] = scoreArrayList.size() - (lo);
            answerIndex += 1;
            // scoreArrayList.size() - 1;
            //scoreArrayList.size() - (lo + 1);
            // if (findTarget == true) {
            //     System.out.println("Found");
            //     System.out.println("lo=" + lo + " hi=" + hi + " diff=" + (hi - lo) + "size=" + scoreArrayList.size() + " end=" + scoreArrayList.get(scoreArrayList.size() - 1));
            //     System.out.println("data=" + scoreArrayList.get(lo));
            //     System.out.println("data=" + scoreArrayList.get(hi));
            // } else {
            //     System.out.println("Not Found");
            //     System.out.println("lo=" + lo + " hi=" + hi + " diff=" + (hi - lo) + "size=" + scoreArrayList.size() + " end=" + scoreArrayList.get(scoreArrayList.size() - 1));
            //     System.out.println("data=" + scoreArrayList.get(lo));
            // }
        }

        return answer;
    }

    // String lang;
    // String job;
    // String year;
    // String food;
    // int  score;

    static void dfs(int index, String key, String [] tokens) {
        if (index == 4) {

            // System.out.println("key=" + key);
            // aMap.get(key);
            ArrayList <Integer> arr = new ArrayList<>();
            if (aMap.containsKey(key)) {
                arr = aMap.get(key);
            }
            arr.add(Integer.parseInt(tokens[4]));

            //Collections.sort(arr);
            aMap.put(key, arr);

            return ;
        }

        String key1 = key;
        String key2 = key;
        //key1 = key1.concat("and");
        key1 = key1.concat(tokens[index]);
        dfs(index + 1, key1, tokens);
        //key2 = key2.concat("and");
        key2 = key2.concat("-");
        dfs(index + 1, key2, tokens);
    }
}

