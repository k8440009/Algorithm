import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class Java_17680 {
    public static void main(String[] args) {        
        Solution_17680 test = new Solution_17680();
        int cacheSize = 3;
        String [] cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
        int answer = test.solution(cacheSize, cities);
        System.out.println(answer);
    }
}

class Solution_17680 {
    static int cache_hit = 1;
    static int cache_miss = 5;
/**
 * 1. hMap에 저장되어 있는지 확인
 * - 있는 경우 hit
 * - 없는 경우 miss
 * 
 * 2. queue 크기 확인
 * 1) hit
 * - 캐시 찾아서 pop
 * - 맨 뒤로
 * 2) miss
 * 2-1) 캐시 사이즈보다 작은경우
 * - 맨 뒤로
 * 2-2) 같거나 큰 경우
 * - 맨 앞 pop
 * - 
 * @param cacheSize
 * @param cities
 * @return
 */
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        Map <String, String> hMap = new HashMap<>();
        Queue <String> queue = new LinkedList<>();
        Queue <String> tmpQue = new LinkedList<>();
        for (String city : cities) {
            
            city = city.toUpperCase();

            if (hMap.containsKey(city)) { // hit
                answer += cache_hit;
                // String cur = tmpQue.poll();
                while(!queue.isEmpty()) {
                    String cur = queue.poll();
                    if (!city.equals(cur)){
                        tmpQue.add(cur);
                    }
                }
                tmpQue.add(city);

                queue.clear();
                while(!tmpQue.isEmpty()) {
                    String cur = tmpQue.poll();
                    queue.add(cur);
                }

            } else { // miss
                answer += cache_miss;
                if (queue.size() < cacheSize) {
                    queue.add(city);
                    hMap.put(city, city);
                } else {
                    String top = queue.poll();
                    hMap.remove(top);

                    queue.add(city);
                    hMap.put(city, city);
                }
            }
        }
        return answer;
    }
}
