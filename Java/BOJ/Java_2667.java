import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.stream.Collectors;

public class Java_2667 {
    static int N;
    static String board[][];
    static boolean visited[][];
    static int cnt = 0, totalCnt = 0;
    static int [] dr = {-1, 0, 1, 0};
    static int [] dc = {0, 1, 0, -1};
    static ArrayList<Integer> arrayList = new ArrayList<Integer>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        board = new String[N][N];
        visited = new boolean[N][N];

        for (int r = 0; r < N; r++){
            String [] tokens = br.readLine().split("");

            for (int c = 0; c < N; c++){
                board[r][c] = tokens[c];
            }
        }

        for (int r = 0; r < N; r++){
            for (int c = 0; c < N; c++){
                if ("1".equals(board[r][c]) == true && visited[r][c] == false){
                    cnt = 0;
                    dfs(r, c);
                    arrayList.add(cnt);
                    totalCnt += 1;
                }
            }
        }
        Collections.sort(arrayList);

        System.out.println(totalCnt);
        Iterator iter = arrayList.iterator();
        while(iter.hasNext()){
            System.out.println(iter.next());
        }
    }

    static void dfs(int r, int c){
        cnt += 1;
        visited[r][c] = true;
        for (int dir = 0; dir < 4; dir++){
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;
            if ("0".equals(board[nr][nc]) == true || visited[nr][nc] == true)
                continue;
            
            dfs(nr, nc);
            
        }
    }
}
