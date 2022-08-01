import java.util.ArrayList;

public class Java_92342 {
    public static void main(String[] args) {
        
    }
}

class Solution {
    static int N;
    static int maxPoint = 0;
    static int apeachPoint = 0;
    ArrayList <Integer> data = new ArrayList<>();
    int [] points = new int [10];
    public int[] solution(int n, int[] info) {
        int[] answer = {};

        N = n;

        apeachPoint = getPoint(info);
        int [] result = new int [10];
        for (int i = 0; i < 10; i++) {
            result[i] += 1;
            dupCombination(i, 1, result, info);
            result[i] -= 1;
        }
        return answer;
    }

    private void dupCombination (int index, int cnt, int [] result, int [] info) {
        if (cnt == N) {
            int lianPoint = getPoint(result);
            
            if (lianPoint > apeachPoint) {
                int diff = lianPoint - apeachPoint;
                // getPoint(info, result);
                if (maxPoint >= diff) {
                    maxPoint = diff;
    
                    if (maxPoint == diff) {
                        int chk = chkRowPoint(points, result);
                    } else {
                        for (int i = 0; i < 10; i++) {
                            points[i] = result[i];
                        }
                    }
                }
            }
            return ;
        }

        
        for (int i = index; i < 10; i++) {
            result[i] += 1;
            dupCombination(index, cnt + 1, result, info);
            result[i] -= 1;
        }
    }

    private int chkRowPoint(int [] before, int [] after) {
        int res = 0;

        for (int i = 9; i >=0; i--) {
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
                }
            }
        }

        return res;
    }

    private int getPoint(int [] points) {
        int res = -1;
        return res;
    }
}