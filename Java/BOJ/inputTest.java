package Java;

import java.io.IOException;
import java.io.InputStream;

public class inputTest {
    public static void main(String[] args) throws IOException{
        InputStream is = System.in;
        int a = is.read();

        System.out.println((char)a);
        System.out.println(a);
    }
}
