import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

public class Java_42889 {
    public static void main(String[] args) {
        Solution_42889 test = new Solution_42889();
        // int N = 5;
        // int [] stages = {2, 1, 2, 6, 2, 4, 3, 3};
        int N = 4;
        int [] stages = {4,4,4,4,4};
        int [] answers = test.solution(N, stages);
        for (int answer : answers) {
            System.out.print(answer + " ");
        }
    }
}

class Failure {
    double fail;
    int stage;
    Failure(double fail, int stage) {
        this.fail = fail;
        this.stage = stage;
    }
}

class FailureComparator implements Comparator<Failure> {
    @Override
    public int compare(Failure o1, Failure o2) {
        if (o1.fail > o2.fail) {
            return -1;
        } else if (o1.fail < o2.fail) {
            return 1;
        } else {
            if (o1.stage > o2.stage) {
                return 1;
            } else if (o1.stage < o2.stage){
                return -1;
            } else {
                return 0;
            }
        }
    }
}

class Solution_42889 {
    public int[] solution(int N, int[] stages) {
        int[] answer = new int [N];
        Map <Integer, Integer> userData = new HashMap <Integer, Integer>(); // stage, userCnt
        ArrayList <Failure> failArr = new ArrayList<Failure>(); // fail, stage

        for (int n = 1; n <= N; n++) {
            userData.put(n, 0);
        }

        for (int stage : stages) {
            if (userData.containsKey(stage)) {
                int usrCnt = userData.get(stage);
                userData.put(stage, usrCnt + 1);
            }
        }

        int totalUser = stages.length;
        // failArr.add(new Failure(0, 0));
        for (int n = 1; n <= N; n++) {
            int stage = n;
            int stageUserCnt = userData.get(stage);

            double fail = 0;

            // System.out.println("stageUserCnt=" + stageUserCnt + " totalUser=" + totalUser);
            if (stageUserCnt != 0 && totalUser != 0) {
                fail = (double)stageUserCnt / (double)totalUser;
            }
            failArr.add(new Failure(fail, stage));
            totalUser -= stageUserCnt;
        }
        Collections.sort(failArr, new FailureComparator());

        int index = 0;
        for (Failure failure : failArr) {
            answer[index] = failure.stage;
            index += 1;
            // System.out.println("fail=" + failure.fail + " stage=" + failure.stage);
        }
        return answer;
    }
}
