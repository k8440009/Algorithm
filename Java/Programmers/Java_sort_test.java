import java.util.ArrayList;
import java.util.Collections;

class Student implements Comparable<Student>{
    String name;
    int age;

    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    /**
     * 오른차순
     * -1 : 왼쪽
     * 0 : pass
     * 1 : 오른쪽
     */
    @Override
    public int compareTo(Student o) {
        if (this.age > o.age) {
            return 1;
        } else if (this.age < o.age) {
            return -1;
        } else {
            return 0;
        }
    }
}

public class Java_sort_test {
    public static void main(String[] args) {
        ArrayList<Student> nameList = new ArrayList<>();

        nameList.add(new Student("a", 1));
        nameList.add(new Student("c", 5));
        nameList.add(new Student("d", 3));

        System.out.println("정렬전");
        for (Student st : nameList) {
            System.out.println("name=" + st.name + " age=" + st.age);
        }
        System.out.println();
        Collections.sort(nameList);
        System.out.println("정렬후");
        for (Student st : nameList) {
            System.out.println("name=" + st.name + " age=" + st.age);
        }
        System.out.println();
    }
}
