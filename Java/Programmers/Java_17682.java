import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Java_17682 {
    public static void main(String[] args) {
        Solution_17682 test = new Solution_17682();
        String dartResult = "1S2D*3T";
        // String dartResult = "1D2S#10S";
        System.out.println("answer=" + test.solution(dartResult));
    }
}

class Solution_17682 {
    public int solution(String dartResult) {
        int answer = 0;
        int [] point = new int [3];
        Pattern p = Pattern.compile("([0-9]+)([SDT])([*#]?)");
        Matcher m = p.matcher(dartResult);

        int index = 0;
        while(m.find()) {
            String str = m.group();
            String [] points = str.split("[SDT]");
            String stage = "";
            String [] tokens = str.split("");
            String option = "";

            int second = 0;
            if (points.length == 2) {
                option = points[1];
            }

            for (String token : tokens) {
                if ("S".equals(token)) {
                    second = 1;
                    stage = "S";
                    break;
                } else if ("D".equals(token)) {
                    second = 2;
                    stage = "D";
                    break;
                } else if ("T".equals(token)) {
                    second = 3;
                    stage = "T";
                    break;
                }
            }

            point[index] =  (int)Math.pow(Integer.parseInt(points[0]), second);

            if ("*".equals(option) == true) {
                if (index == 0) {
                    point[0] *= 2;
                } else if (index == 1) {
                    point[0] *= 2;
                    point[1] *= 2;
                } else if (index == 2) {
                    point[1] *= 2;
                    point[2] *= 2;
                } 
            } else if ("#".equals(option) == true){
                if (index == 0) {
                    point[0] *= (-1);
                } else if (index == 1) {
                    point[1] *= (-1);
                } else if (index == 2) {
                    point[2] *= (-1);
                } 
            }
            index += 1;
        }
        
        answer = point[0] + point[1] + point[2];
        return answer;
    }
}