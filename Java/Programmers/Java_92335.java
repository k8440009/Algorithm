public class Java_92335 {
    public static void main(String[] args) {
        Solution_92335 test = new Solution_92335();
        // int n = 437674;
        // int k = 3;
        // int n = 1100011;
        // int k = 10;
        // int n = 0;
        // int k = 2;
        // 1,000,000

        int N = 1000000;
        for (int n = 1; n <= N; n++) {
            int k = 2;
            System.out.println("n=" + n);
            System.out.println(test.solution(n, k));
        }
        
        // int n = 2047;
        // int k = 2;
        // System.out.println(test.solution(n, k));
    }
}

class Solution_92335 {
    public int solution(int n, int k) {
        int answer = 0;
        String str = Integer.toString(n, k);

        String [] tokens = str.split("0");
        for (String token : tokens) {
            if ("".equals(token) == false) {
                long num = Long.parseLong(token);
    
                if (isPrime(num) == true) {
                    answer += 1;
                }
            }
        }
        return answer;
    }

    public boolean isPrime(long num) {
        boolean result = true;
        long sqrtNum = (long)Math.sqrt(num);
        if (num == 1) {
            return false;
        } else {
            for (long i = 2; i <= sqrtNum; i++) {
                if (num % i == 0) {
                    result = false;
                    break;
                }
            }
        }
        return result;
    }
}

