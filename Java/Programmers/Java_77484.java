public class Java_77484 {
    public static void main(String[] args) {
        Solution_77484 test = new Solution_77484();
        int [] lottos =  {44, 1, 0, 0, 31, 25};
        int [] win_nums = {31, 10, 45, 1, 6, 19};
        
        int [] results = test.solution(lottos, win_nums);
        for (int result : results) {
            System.out.print(result + " ");
        }
        System.out.println();
    }
}

class Solution_77484 {
    public int[] solution(int[] lottos, int[] win_nums) {
        int [] answer = new int[2];
        int zeroCnt = 0;
        int matchCnt = 0;
        for (int i = 0; i < lottos.length; i++) {
            if (lottos[i] == 0) {
                zeroCnt += 1;
            }
        }

        for (int i = 0; i < win_nums.length; i++) {
            for (int j = 0; j < lottos.length; j++) {
                if (lottos[j] == 0) {
                    continue;
                } else {
                    if (win_nums[i] == lottos[j]) {
                        matchCnt += 1;
                        break;
                    }
                }
            }
        }
        answer[0] = getPoint(matchCnt + zeroCnt);
        answer[1] = getPoint(matchCnt);

        return answer;
    }

    public int getPoint(int matchCnt) {
        int res = -1;
        switch(matchCnt) {
            case 6:
            res = 1;
            break;
            case 5:
            res = 2;
            break;
            case 4:
            res = 3;
            break;
            case 3 :
            res = 4;
            break;
            case 2 :
            res = 5;
            break;
            default :
            res = 6;
            break;
        }
        return res;
    }
}