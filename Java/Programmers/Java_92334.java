import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;

class Solution_92334 {
    public int[] solution(String[] id_list, String[] reports, int k) {
        int [] result = new int [id_list.length];
        Map <String, Integer> idMap = new HashMap<String, Integer>();
        HashSet <String> hashSet = new HashSet<String>();
        ArrayList <ArrayList<String>> arrayLists = new ArrayList<ArrayList<String>>();
        
        int idx = 0;
        for (String id : id_list) {
            ArrayList <String> idArray = new ArrayList<String>();
            arrayLists.add(idArray);

            idMap.put(id, idx);
            idx += 1;
        }

        for (String report : reports) {
            hashSet.add(report);
        }

        Iterator iterator = hashSet.iterator();
        while (iterator.hasNext()) {
            String report = (String)iterator.next();
            String [] tokens = report.split(" ");
            String reporter = tokens[0];
            String reported = tokens[1];

            if (idMap.containsKey(reported)) {
                int index = idMap.get(reported);
                ArrayList<String> arr = arrayLists.get(index);
                arr.add(reporter);
            }
        }
        for (ArrayList <String> arr : arrayLists) {
            if (arr.size() >= k) {
                for (String reporter : arr) {
                    int index = idMap.get(reporter);
                    result[index] += 1;
                }
            }
        }
        return result;
    }
}

public class Java_92334 {
    public static void main(String[] args) {
        Solution_92334 test = new Solution_92334();
        String [] id_list = {"muzi", "frodo", "apeach", "neo"};
        String [] reports = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
        int k = 2; 
        // String [] id_list = {"con", "ryan"};
        // String [] reports = {"ryan con", "ryan con", "ryan con", "ryan con"};
        // int k = 3; 

        int [] results = test.solution(id_list, reports, k);
        for (int result : results) {
            System.out.print(result + " ");
        }
        System.out.println();
    }
}