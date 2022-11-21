import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
1991 트리 순회
 7
A B C
B D .
C E F
E . .
F . G
D . .
G . .

 */
public class Java_1991 {
    static int [] lc;
    static int [] rc;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        lc = new int [N + 1];
        rc = new int [N + 1];
        for (int i = 0; i < N; i++) {
            String [] tokens = br.readLine().split(" ");
            
            int index = tokens[0].charAt(0) - 'A' + 1;
            if (".".equals(tokens[1]) == false) {
                lc[index] = tokens[1].charAt(0) - 'A' + 1;
            }

            if (".".equals(tokens[2]) == false){
                rc[index] = tokens[2].charAt(0) - 'A' + 1;
            }
        }

        preorder(1);
        System.out.println();
        inorder(1);
        System.out.println();
        postorder(1);
        System.out.println();
    }
    /**
     * preorder (전위순회)
     * 1. 현재 정점 방문
     * 2. 왼쪽 전위  순회
     * 3. 오른쪽 전위  순회
     * @param now
     */
    public static void preorder(int now) {
        System.out.print((char)('A' + now - 1));
        if (lc[now] != 0) {
            preorder(lc[now]);
        }
        if (rc[now] != 0) {
            preorder(rc[now]);
        }
    }
    /**
     * inorder (중위순회)
     * 1. 왼쪽 서브트리 중위 순회
     * 2. 현재 정점 방분
     * 3. 오른쪽 서브트리 중위 순회
     * @param now
     */
    public static void inorder(int now) {
        if (lc[now] != 0) {
            inorder(lc[now]);
        }
        System.out.print((char)('A' + now - 1));
        if (rc[now] != 0) {
            inorder(rc[now]);
        }
    }
    /**
     * postorder (후위순회)
     * 1. 왼쪽 서브트리 후위 순회
     * 2. 현재 정점 방문
     * 3. 오른쪽 서브트리 후위 순회
     * @param now
     */
    public static void postorder(int now) {
        if (lc[now] != 0) {
            postorder(lc[now]);
        }
        if (rc[now] != 0) {
            postorder(rc[now]);
        }
        System.out.print((char)('A' + now - 1));
    }
}
