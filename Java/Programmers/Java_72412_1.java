import java.util.ArrayList;

/**
 * 정확성 : 40점
 * 효율성 : 0점
 * 
 * 푸는데 걸린 시간 : 40분 => 30분정도 되야함
 * 
 * @since 2022-09-05
 * @author SungSoo Lee
 */
public class Java_72412_1 {
    public static void main(String[] args) {

        Solution_72412_1 test = new Solution_72412_1();
        String [] infos = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
        String [] querys = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
        int [] answers = test.solution(infos, querys);
        for (int i = 0; i < answers.length; i++) {
            System.out.print(answers[i] + " ");
        }
        System.out.println();
    }
}

class People_72412_1 {
    String lang;
    String job;
    String year;
    String food;
    int  score;

    People_72412_1(String lang, String job, String year, String food, int score) {
        this.lang = lang;
        this.job = job;
        this.year = year;
        this.food = food;
        this.score = score;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lang).append(" ").append(this.job).append(" ").append(this.year).append(" ").append(this.food).append(" ").append(Integer.toString(score));
        return sb.toString();
    }
}

class Solution_72412_1 {
    public int[] solution(String[] infos, String[] querys) {
        int[] answer = new int [querys.length];

        ArrayList <People_72412_1> arrayList = new ArrayList<>();

        for (String info : infos) {
            String [] tokens = info.split(" ");

            arrayList.add(new People_72412_1(tokens[0], tokens[1], tokens[2], tokens[3], Integer.parseInt(tokens[4])));
        }

        int index = 0;
        for (String query : querys) {
            String [] tokens = query.split("and");
            
            String lang = tokens[0].trim();
            String job = tokens[1].trim();
            String year = tokens[2].trim();

            String [] splitStr = tokens[3].trim().split(" ");
            String food = splitStr[0].trim();
            int  score = Integer.parseInt(splitStr[1].trim());


            int cnt = 0;
            for (People_72412_1 people : arrayList) {
                // if (index != 2)
                //     break;

                // System.out.println(index);
                // System.out.println(people.toString());
                if ("-".equals(lang) == false
                    && people.lang.equals(lang) == false) {
                        //System.out.println("hello1");
                        continue;
                }

                if ("-".equals(job) == false
                && people.job.equals(job) == false) {
                    //System.out.println("hello2");
                    continue;
                }

                if ("-".equals(year) == false
                        && people.year.equals(year) == false) {
                           // System.out.println("hello3");
                            continue;
                    }

                if ("-".equals(food) == false
                    && people.food.equals(food) == false) {
                       // System.out.println("hello4");
                        continue;
                }

                if (people.score >= score) {
                    cnt += 1;
                } else {
                   // System.out.println("hello5");
                }
            }

            answer[index] = cnt;
            index += 1;
        }
        return answer;
    }
}