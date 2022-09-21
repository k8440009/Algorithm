public class Java_118668_1 {
    public static void main(String[] args) {
        
        Solution_118668_1 test = new Solution_118668_1();

        System.out.println("test1");
        int[][] problems1 = {{10,15,2,1,2},{20,20,3,3,4}};
        System.out.println(test.solution(10, 10, problems1));

        System.out.println("test2");
        int[][] problems2 = {{0,0,2,1,2},{4,5,3,1,2},{4,11,4,0,2},{10,4,0,4,2}};
        System.out.println(test.solution(0, 0, problems2));
    }
}

class Solution_118668_1{
    public int solution(int alp, int cop, int[][] problems) {
        int max_alp_req = 0;
        int max_cop_req = 0;

        for (int [] problem : problems) {
            max_alp_req = Math.max(problem[0], max_alp_req);
            max_cop_req = Math.max(problem[1], max_cop_req);
        }

        if (max_alp_req <= alp && max_cop_req <= cop) {
            return 0;
        }

        
        if (alp >= max_alp_req) {
            alp = max_alp_req;
        }
        
        if (cop >= max_cop_req) {
            cop = max_cop_req;
        }
        
        int [][] dp = new int [max_alp_req + 2][max_cop_req + 2]; 
        for (int r = alp; r <= max_alp_req; r++) {
            for (int c = cop; c <= max_cop_req; c++) {
                dp[r][c] = Integer.MAX_VALUE;
            }
        }

        dp[alp][cop] = 0;
        for (int i = alp; i <= max_alp_req; i++) {
            for (int j = cop; j <= max_cop_req; j++) {
                dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j] + 1);
                dp[i][j + 1] = Math.min(dp[i][j + 1], dp[i][j] + 1);

                for (int [] p : problems) {
                    // 요구
                    if (i >= p[0] && j >= p[1]) {
                        if (i + p[2] > max_alp_req && j + p[3] > max_cop_req) {
                            dp[max_alp_req][max_cop_req] = Math.min(dp[max_alp_req][max_cop_req], dp[i][j] + p[4]);
                        } else if (i + p[2] > max_alp_req) {
                            dp[max_alp_req][j + p[3]] = Math.min(dp[max_alp_req][j + p[3]], dp[i][j] + p[4]);
                        } else if (j + p[3] > max_cop_req) {
                            dp[i + p[2]][max_cop_req] = Math.min(dp[i + p[2]][max_cop_req], dp[i][j] + p[4]);
                        } else if (i + p[2] <= max_alp_req && j + p[3] <= max_cop_req) {
                            dp[i + p[2]][j + p[3]] = Math.min(dp[i + p[2]][j + p[3]], dp[i][j] + p[4]);
                        }
                    }
                }
            }
        }
        // System.out.println(max_alp_req + " "  + max_cop_req);
        return dp[max_alp_req][max_cop_req];
    }
}
