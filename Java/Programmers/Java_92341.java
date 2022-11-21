import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

public class Java_92341 {
    public static void main(String[] args) {
        Solution_92341 test = new Solution_92341();
        int [] fees = {180, 5000, 10, 600};
        String [] records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
        // int [] fees = {120, 0, 60, 591};
        // String [] records = {"16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"};
        // int [] fees = {1, 461, 1, 10};
        // String [] records = {"00:00 1234 IN"};
        int [] answers = test.solution(fees, records);

        for (int answer : answers) {
            System.out.print(answer + " ");
        }
        System.out.println();
    }
}

class Solution_92341 {
        public int[] solution(int[] fees, String[] records) {
            int[] answer = null;

            Map <String, String> checkPark = new HashMap<String, String>();
            Map <String, Integer> saveTime = new HashMap<String, Integer>();
             for (String record : records) {
                String [] tokens = record.split(" ");

                String time = tokens[0];
                String carNum = tokens[1];

                if (checkPark.containsKey(carNum) == true) {
                    int parkTime = 0;
                    parkTime = calcuateTime(checkPark.get(carNum), time);

                    if (saveTime.containsKey(carNum) == true) {
                        saveTime.put(carNum, saveTime.get(carNum) + parkTime);
                    } else {
                        saveTime.put(carNum, parkTime);
                    }
                    checkPark.remove(carNum);
                } else {
                    checkPark.put(carNum, time);
                }
             }

             for (Map.Entry<String, String> entry : checkPark.entrySet()) {
                String carNum = entry.getKey();
                String startTime = entry.getValue();
                int parkTime = calcuateTime(startTime, "23:59");

                if (saveTime.containsKey(carNum) == true) {
                    saveTime.put(carNum, saveTime.get(carNum) + parkTime);
                } else {
                    saveTime.put(carNum, parkTime);
                }
             }

             List <String> keySet = new ArrayList<String>(saveTime.keySet());
             Collections.sort(keySet);

             answer = new int[keySet.size()];
             int index = 0;
             for (String key : keySet) {
                answer[index] = calculateFee(saveTime.get(key), fees);
                index += 1;
             }
             return answer;
        }
        public int calcuateTime (String startTime, String endTime) {
            int cal = 0;
            String [] tokens = null;
            String hh1 = null;
            String hh2 = null;
            String mm1 = null;
            String mm2 = null;
            tokens = startTime.split(":");

            hh1 = tokens[0];
            mm1 = tokens[1];

            tokens = endTime.split(":");
            hh2 = tokens[0];
            mm2 = tokens[1];

            cal = (Integer.parseInt(hh2) * 60 + Integer.parseInt(mm2))
                - (Integer.parseInt(hh1) * 60 + Integer.parseInt(mm1));

            return cal;
        }
        public int calculateFee(int times, int [] fees) {
            int fee = 0;
            if (times <= fees[0]) {
                fee = fees[1];
            } else {
                int modTime = times - fees[0];
                fee = fees[1];

                int mod = modTime / fees[2];
                if (modTime % fees[2] == 0) {
                    fee += fees[3] * mod;
                } else {
                    fee += fees[3] * (mod + 1);
                }
            }
            return fee;
        }
}