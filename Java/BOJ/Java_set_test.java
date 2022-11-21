import java.util.HashSet;
import java.util.Set;

public class Java_set_test {
    public static void main(String[] args) {
        Set <Integer> s1 = new HashSet<>(); // 1, 2, 3, 4 
        Set <Integer> s2 = new HashSet<>(); // 3, 4, 5, 6
        Set <Integer> s3 = new HashSet<>(); // 3, 4

        s1.add(1);
        s1.add(2);
        s1.add(3);
        s1.add(4);

        s2.add(3);
        s2.add(4);
        s2.add(5);
        s2.add(6);

        s3.add(3);
        s3.add(4);
        // 1. 합집합 - addAll()
        System.out.println("addAll()");
        s1.addAll(s2); // 1, 2, 3, 4, 5, 6
        for (int n : s1) {
            System.out.print(n + " ");
        }
        System.out.println();
        System.out.println();
        // 2. 교집합 - retainAll()
        System.out.println("retainAll()");
        s1.clear();
        s1.add(1);
        s1.add(2);
        s1.add(3);
        s1.add(4);
        s1.retainAll(s2); // 3, 4
        for (int n : s1) {
            System.out.print(n + " ");
        }
        s1.clear();
        System.out.println();
        System.out.println();
        // 3. 차집합
        System.out.println("removeAll()");
        s1.clear();
        s1.add(1);
        s1.add(2);
        s1.add(3);
        s1.add(4);
        s1.removeAll(s2); // 1, 2
        for (int n : s1) {
            System.out.print(n + " ");
        }
        System.out.println();
        System.out.println();
        // 4. 부분집합 여부
        System.out.println("containsAll()");
        s1.clear();
        s1.add(1);
        s1.add(2);
        s1.add(3);
        s1.add(4);
        System.out.println("부분집합아님 False=" + s1.containsAll(s2)); // (1, 2, 3, 4) != (3, 4, 5, 6)
        System.out.println("부분집합인 경우 True=" + s1.containsAll(s3)); // (1, 2, 3, 4) 에 포함되는 (3, 4)


    }
}
