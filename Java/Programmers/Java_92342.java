import java.util.ArrayList;

public class Java_92342 {
    public static void main(String[] args) {
        Solution_92342 test = new Solution_92342();

        // int n = 5;
        // int [] info = {2,1,1,1,0,0,0,0,0,0,0};
        // int n = 1;
        // int [] info = {1,0,0,0,0,0,0,0,0,0,0};
        // int n = 9;
        // int [] info = {0,0,1,2,0,1,1,1,1,1,1};
        int n = 10;
        int [] info = {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3};

        int [] results = test.solution(n, info);

        // System.out.println();
        // for (int result : results) {
        //     System.out.print(result + " ");
        // }

    }
}

class Solution_92342 {
    int [] rion;
    int [] maxDiffArrow;
    int maxDiff = 0;
    public int[] solution(int n, int[] infos) {
        int[] answer = {-1};
        
        rion = new int [11]; // 0 ~ 10 과녁, 화살 갯수
        maxDiffArrow = new int [11]; // 상태

        // n발 선택
        combination(0, 0, n, infos);

        if (maxDiff != 0) {
            answer = maxDiffArrow;
        }
        return answer;
    }

    public void combination(int index, int total_cnt, int n, int [] infos) {
        if (total_cnt > n) { // 화살 갯수가 초과하면 종료
            return ;
        }
        
        if (index == 11) {
            if (total_cnt == n) { // 화살 갯수
                int apeachPoint = 0;
                int rionPoint = 0;
                for (int i = 0; i <= 10; i++) {
                    if (rion[i] == 0 && infos[i] == 0)
                        continue;

                    if (rion[i] > infos[i]) {
                        rionPoint += (10 - i);
                    } else {
                        // 모두 어치피 승리
                        apeachPoint += (10 - i);
                    }
                }
                
                if (rionPoint > apeachPoint) {
                    int diff = rionPoint - apeachPoint;
                    
                    if (diff > maxDiff) {
                        maxDiff = diff;
                        for (int i = 0; i <= 10; i++) {
                            maxDiffArrow[i] = rion[i];
                        }
                    } else if (diff == maxDiff) {
                        boolean flag = false;
                        for (int i = 10; i >= 0; i--) {
                            if (rion[i] == 0 && maxDiffArrow[i] == 0)
                                continue;

                            if (rion[i] > maxDiffArrow[i]) {
                                flag = true;
                                break;
                            } else if (rion[i] < maxDiffArrow[i]) {
                                break;
                            }
                        }

                        if (flag) {
                            for (int i = 0; i <= 10; i++) {
                                maxDiffArrow[i] = rion[i];
                            }
                        }
                    }
                }
            }

            return ;
        }

        for (int cnt = 0; cnt <= n; cnt++) {
            rion[index] = cnt;
            combination(index + 1, total_cnt + cnt, n, infos);
            rion[index] = -1;
        }
    }
}