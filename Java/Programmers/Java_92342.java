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

        System.out.println();
        for (int result : results) {
            System.out.print(result + " ");
        }

    }
}

class Solution_92342 {
    static int N;
    static int maxPoint = 0;
    static int maxLength = 11;
    ArrayList <Integer> data = new ArrayList<>();
    int [] points = new int [11];

    public int[] solution(int n, int[] info) {
        int[] answer = null;

        N = n;

        int [] result = new int [11];
        dupCombination(0, 0, result, info);
        
        if (maxPoint == 0) {
            answer = new int[1];
            answer[0] = -1;
        } else {
            answer = new int[11];
            for (int i = 0; i < 11; i++) {
                answer[i] = points[i];
            }
        }
        return answer;
    }
    
    private void dupCombination (int index, int cnt, int [] result, int [] info) {
        if (cnt == N) {
            int point = getDiffPoint(result, info);

            if (point != -1) {
                if (point >= maxPoint) {
                    
                    int chk = 1;
                    if (maxPoint == point) {
                        chk = chklowPoint(points, result);
                    }
                    
                    maxPoint = point;

                    if (chk == 1) {
                        for (int i = 0; i < 11; i++) {
                            points[i] = result[i];
                        }
                    }
                }
            }
            return ;
        }

        for (int i = index; i < 11; i++) {
            result[i] += 1;
            dupCombination(i, cnt + 1, result, info);
            result[i] -= 1;
        }
    }

    private int getDiffPoint(int [] lian, int [] apeach) {
        int res = -1;
        int lianPoint = 0;
        int apeachPoint = 0;

        for (int i = 0; i < 10; i++) {
            int point = 10 - i;

            if (lian[i] == 0 && apeach[i] == 0) {
                continue;
            }else if (lian[i] == 0 && apeach[i] != 0) {
                apeachPoint += point;
            } else if (lian[i] != 0 && apeach[i] == 0) {
                lianPoint += point;
            } else {
                if (lian[i] > apeach[i]) {
                    lianPoint += point;
                } else {
                    apeachPoint += point;
                }
            }
        }

        if (lianPoint > apeachPoint) {
            res = lianPoint - apeachPoint;
        }

        return res;

    }
    private int chklowPoint(int [] before, int [] after) {
        int res = 0;

        for (int i = 10; i >=0; i--) {
            if (before[i] == 0 && after[i] == 0) {
                continue;
            }

            if (before[i] == 0 && after[i] != 0){
                res = 1;
                break;
            } else if (before[i] != 0 && after[i] == 0) {
                res = -1;
                break;
            } else {
                if (before[i] > after[i]) {
                    res = -1;
                    break;
                } else if (before[i] < after[i]) {
                    res = 1;
                    break;
                }
            }
        }
        return res;
    }
}