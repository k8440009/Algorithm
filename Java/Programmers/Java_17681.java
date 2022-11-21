public class Java_17681 {
    public static void main(String[] args) {
        Solution_17681 test = new Solution_17681();
        int n = 5;
        int [] arr1 = {9, 20, 28, 18, 11};
        int [] arr2 = {30, 1, 21, 17, 28};
        String [] answers = test.solution(n, arr1, arr2);
        for (String answer : answers){
            System.out.println(answer);
        }
    }
}

class Solution_17681 {
        public String[] solution(int n, int[] arr1, int[] arr2) {
            String[] answer = new String[n];
            StringBuilder sb = new StringBuilder();

            for (int r = 0; r < n; r++) {
                String arr1Binarys = Integer.toBinaryString(arr1[r]);
                String arr2Binarys = Integer.toBinaryString(arr2[r]);

                sb.setLength(0);
                if (arr1Binarys.length() != n) {
                    int zeroCnt = n - arr1Binarys.length();
                    for (int cnt = 0; cnt < zeroCnt; cnt++) {
                        sb.append("0");
                    }
                    sb.append(arr1Binarys);

                    arr1Binarys = sb.toString();
                }

                sb.setLength(0);
                if (arr2Binarys.length() != n) {
                    int zeroCnt = n - arr2Binarys.length();
                    for (int cnt = 0; cnt < zeroCnt; cnt++) {
                        sb.append("0");
                    }
                    sb.append(arr2Binarys);

                    arr2Binarys = sb.toString();
                }

                String [] arr1BinarySplit = arr1Binarys.split("");
                String [] arr2BinarySplit = arr2Binarys.split("");

                sb.setLength(0);
                for (int c = 0; c < n; c++) {
                    if ("1".equals(arr1BinarySplit[c]) || "1".equals(arr2BinarySplit[c])) {
                        sb.append("#");
                    } else {
                        sb.append(" ");
                    }
                }
                answer[r] = sb.toString();
            }
            return answer;
        }
}