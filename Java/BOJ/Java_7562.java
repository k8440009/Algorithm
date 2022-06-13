import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Night {
    int r, c;
    int cnt;

    Night(int r, int c, int cnt) {
        this.r = r;
        this.c = c;
        this.cnt = cnt;
    }
}
public class Java_7562 {
    static int [] dr = {-2, -2, -1, 1, 2, 2,  1, -1};
    static int [] dc = {-1, 1,  2,  2, 1, -1, -2, -2};
    static int [][] board = null;
    static boolean [][] visited = null;
    static int minCnt = -1;
    static int N;
    static Queue <Night> queue = null;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testCase = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < testCase; tc++) {
            N = Integer.parseInt(br.readLine());
            minCnt = -1;
            board = new int [N][N];
            visited = new boolean [N][N];
            queue = new LinkedList<Night>();
            String [] tokens = br.readLine().split(" ");
            int startR = Integer.parseInt(tokens[0]);
            int startC = Integer.parseInt(tokens[1]);

            tokens = br.readLine().split(" ");
            int targetR = Integer.parseInt(tokens[0]);
            int targetC = Integer.parseInt(tokens[1]);

            queue.add(new Night(startR, startC, 0));
            visited[startR][startC] = true;
            bfs(targetR, targetC);

            System.out.println(minCnt);
        }
    }

    public static void bfs(int tr, int tc) {

        while(!queue.isEmpty()) {
            Night cur = queue.poll();

            if (cur.r == tr && cur.c == tc) {
                minCnt = cur.cnt;
                break;
            }

            for (int dir = 0; dir < 8; dir++) {
                int nr = cur.r + dr[dir];
                int nc = cur.c + dc[dir];

                if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] == true) {
                    continue;
                }

                queue.add(new Night(nr, nc, cur.cnt + 1));
                visited[nr][nc] = true;
            }
        }
    }
}
