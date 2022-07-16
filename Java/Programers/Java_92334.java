import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Objects;
import java.util.Set;


class Data {
    String reporter, reported;

    Data(String reporter, String reported) {
        this.reporter = reporter;
        this.reported = reported;
    }
}

class Solution {
    public int[] solution(String[] id_list, String[] reports, int k) {
        int [] result = new int[id_list.length];
        HashMap <String, Integer> reportIdList = new HashMap<String, Integer>();
        HashSet <Data> datas = new HashSet<Data>();

        for (String id : id_list) {
            reportIdList.put(id, 0);
        }

        Iterator iterator = null;
        for (String report : reports) {
            String [] tokens = report.split(" ");
            String reporter = tokens[0];
            String reported = tokens[1];
            boolean addFlag = true;
            iterator = datas.iterator();
            //System.out.println("reporter=" + reporter + " reported=" + reported);
            
            while(iterator.hasNext()) {
                Data data = (Data)iterator.next();
                String reporter1 = data.reporter;
                String reported1 = data.reported;
                
                // System.out.print("reporter=" + reporter + " reporter1=" + reporter1);
                // System.out.println();
                // System.out.print("reported=" + reported + " reported1=" + reported1);
                // System.out.println();
                if (reported.equals(reported1) && reporter.equals(reporter1)) {
                    addFlag = false;
                    break;
                }
            }

            if (addFlag) {
                datas.add(new Data(reporter, reported));
            }
        }

        iterator = datas.iterator();
        while(iterator.hasNext()) {
            Data data = (Data)iterator.next();
            String reported = data.reported;
            String reporter = data.reporter;

            if (reportIdList.containsKey(reported)) {
                int cnt = reportIdList.get(reported);
                reportIdList.put(reported, cnt + 1);
            }
        }

        // System.out.println("datas_size=" + datas.size());
        iterator = datas.iterator();
        while(iterator.hasNext()) {
            Data data = (Data)iterator.next();
            String reported = data.reported;
            String reporter = data.reporter;

            if (reportIdList.containsKey(reported)) {
                int cnt = reportIdList.get(reported);
                if (cnt >= k) {
                    int idx = 0;
                    for (String id : id_list) {
                        if (id.equals(reporter)) {
                            result[idx] += 1;
                            break;
                        }
                        idx += 1;
                    }
                }
            }
        }
        return result;
    }
}

public class Java_92334 {
    public static void main(String[] args) {
        Solution test = new Solution();
        // String [] id_list = {"muzi", "frodo", "apeach", "neo"};
        // String [] reports = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
        // int k = 2; 
        String [] id_list = {"con", "ryan"};
        String [] reports = {"ryan con", "ryan con", "ryan con", "ryan con"};
        int k = 3; 

        int [] results = test.solution(id_list, reports, k);
        for (int result : results) {
            System.out.print(result + " ");
        }
        System.out.println();
    }
}